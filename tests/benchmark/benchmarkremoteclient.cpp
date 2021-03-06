/***************************************************************************
**
** Copyright (C) 2010, 2011 Nokia Corporation and/or its subsidiary(-ies).
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file LICENSE.LGPL included in the packaging
** of this file.
**
****************************************************************************/

#include <stdlib.h>
#include <QTimer>
#include <QDebug>
#include <QPainter>
#include <QImage>
#include <MGConfItem>
#include <QApplication>
#include <QTextStream>

#include "benchmarkremoteclient.h"

using namespace M::MThemeDaemonProtocol;


BenchmarkRemoteClient::BenchmarkRemoteClient() : packetsSent(0)
{
    stream.setDevice(&socket);
    stream.setVersion(QDataStream::Qt_4_6);

    connect(&socket, SIGNAL(connected()), SLOT(connected()));
    connect(&socket, SIGNAL(disconnected()), SLOT(disconnected()));
    connect(&socket, SIGNAL(readyRead()), this, SLOT(readyRead()));

    connect(this, SIGNAL(pixmapReady(MPixmapHandle,M::MThemeDaemonProtocol::PixmapIdentifier)), this, SLOT(updatePixmapStats(MPixmapHandle,M::MThemeDaemonProtocol::PixmapIdentifier)));
}

BenchmarkRemoteClient::~BenchmarkRemoteClient()
{
    if (socket.state() == QLocalSocket::ConnectedState) {
        socket.disconnectFromServer();
    }
}

void BenchmarkRemoteClient::run() {
    // connect to server
    socket.connectToServer(M::MThemeDaemonProtocol::ServerAddress);

    if (!socket.waitForConnected(5000)) {
        qWarning() << "ERROR: failed to connect server:" << socket.error();
        emit finished();
        return;
    }

#ifdef PRINT_INFO_MESSAGES
    qDebug() << "Connected to themedaemon socket";
#endif

    pixmapsToRequest = Common::getPixmapsToRequest();

    registerToServer();
}

void BenchmarkRemoteClient::connected()
{
//    QLocalSocket* socket = qobject_cast<QLocalSocket*>(sender());
}

void BenchmarkRemoteClient::disconnected()
{
//    QLocalSocket* socket = qobject_cast<QLocalSocket*>(sender());
}

void BenchmarkRemoteClient::registerToServer()
{
#ifdef PRINT_INFO_MESSAGES
    qDebug() << "INFO: registering to server";
#endif
    Packet version(Packet::ProtocolVersionPacket, packetsSent++);
    version.setData(new Number(protocolVersion));
    stream << version;

    Packet registration(Packet::RequestRegistrationPacket, packetsSent++);
    registration.setData(new String("benchmark-client"));
    stream << registration;

    sendPacket();
}

M::MThemeDaemonProtocol::Packet BenchmarkRemoteClient::processOnePacket()
{
    Packet packet;
    stream >> packet;

    switch (packet.type()) {
    case Packet::PixmapUpdatedPacket: {
        const PixmapHandle *handle = static_cast<const PixmapHandle *>(packet.data());

        if(handle->pixmapHandle.isValid()) {
            emit pixmapReady(handle->pixmapHandle, handle->identifier);
        } else {
            qWarning() << "ERROR: daemon returned null handle for" << handle->identifier.imageId;
        }
    } break;

    case Packet::ThemeChangedPacket:
        break;
    case Packet::ThemeDaemonStatusPacket:
        break;
    case Packet::ErrorPacket:
        qWarning() << "ERROR: daemon returned error:"
            << static_cast<const String *>(packet.data())->string;
        break;
    default:
        break;
    }

    return packet;
}

void BenchmarkRemoteClient::updatePixmapStats(const MPixmapHandle &handle, const M::MThemeDaemonProtocol::PixmapIdentifier& identifier)
{
    Q_UNUSED(handle);

    QMap<QString, RequestInfo>::iterator requestInfo = requestedPixmaps.find(identifier.imageId);
    Q_ASSERT(requestInfo != requestedPixmaps.end());
    requestedPixmaps.erase(requestInfo);

    requestInfo->answer = QTime::currentTime();
    requestInfo->size = identifier.size;
    readyPixmaps[identifier.imageId] = *requestInfo;
    releasePixmap(identifier);
}

void BenchmarkRemoteClient::readyRead()
{
    while (socket.bytesAvailable() > 0) {
        processOnePacket();
    }
}

void BenchmarkRemoteClient::sendPacket()
{
    if (pixmapsToRequest.count() > 0) {
        QPair<QString,QSize> toRequest = pixmapsToRequest.takeLast();
        PixmapIdentifier pixmapIdentifier(toRequest.first, toRequest.second);
        requestPixmap(pixmapIdentifier);
        QTimer::singleShot(50, this, SLOT(sendPacket()));
    } else {
        QTimer::singleShot(5000, this, SLOT(printResults()));
    }
}

void BenchmarkRemoteClient::requestPixmap(M::MThemeDaemonProtocol::PixmapIdentifier &pixmapIdentifier)
{
#ifdef PRINT_INFO_MESSAGES
    qDebug() << "INFO: requesting pixmap" << pixmapIdentifier.imageId << pixmapIdentifier.size;
#endif
    Packet packet(Packet::RequestPixmapPacket, packetsSent++);
    packet.setData(new RequestedPixmap(pixmapIdentifier, 0));
    stream << packet;

    RequestInfo requestInfo;
    requestInfo.request = QTime::currentTime();
    requestedPixmaps.insert(pixmapIdentifier.imageId, requestInfo);
}

void BenchmarkRemoteClient::releasePixmap(const M::MThemeDaemonProtocol::PixmapIdentifier &pixmapIdentifier)
{
#ifdef PRINT_INFO_MESSAGES
    qDebug() << "INFO: releasing pixmap" << pixmapIdentifier.imageId << pixmapIdentifier.size;
#endif
    Packet packet(Packet::ReleasePixmapPacket, packetsSent++);
    packet.setData(new PixmapIdentifier(pixmapIdentifier));
    stream << packet;
    requestedPixmaps.remove(pixmapIdentifier.imageId);
}

void BenchmarkRemoteClient::printResults() {
    Common::printResults("remote theme daemon", readyPixmaps, requestedPixmaps);
    emit finished();
}
