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

#include "mlocalthemedaemon.h"
#include "mthemedaemonprotocol.h"
#include "mpixmaphandle.h"

using namespace M::MThemeDaemonProtocol;


MLocalThemeDaemon::MLocalThemeDaemon(const QString &applicationName) :
    daemon(MThemeDaemon::LocalDaemon),
    themeItem("/meegotouch/theme/name"),
    locale("/meegotouch/i18n/language")

{
    QString theme =  M_THEME_DEFAULT;
    QString language = "";
    theme = themeItem.value(M_THEME_DEFAULT).toString();
    language = locale.value("en_GB").toString();

    QList<PixmapCacheEntry*> pixmapsToDelete;
    if ( daemon.activateTheme(theme, language, QList<MThemeDaemonClient *>(), pixmapsToDelete) == false ) {
        qWarning() << "Could not activate the theme:" << theme;
    }
    Q_ASSERT(pixmapsToDelete.isEmpty());

    client = new MThemeDaemonClient(NULL, applicationName, daemon.themeInheritanceChain());
    daemon.addClient(client);
}

void MLocalThemeDaemon::registerApplicationName(const QString &applicationName)
{
    client->reinit(applicationName, daemon.themeInheritanceChain());
}

MLocalThemeDaemon::~MLocalThemeDaemon()
{
    daemon.removeClient(client);
    delete client;
    client = NULL;
}

void MLocalThemeDaemon::addDirectoryToPixmapSearchList(const QString &directoryName, M::RecursionMode recursive)
{
    client->addCustomImageDirectory(directoryName, recursive);
}

void MLocalThemeDaemon::clearPixmapSearchList()
{
    client->removeAddedImageDirectories();
}

void MLocalThemeDaemon::pixmapHandleSync(const QString &imageId, const QSize &size)
{
    // request
    MPixmapHandle handle;
    if (daemon.pixmap(client, PixmapIdentifier(imageId, size), &handle)) {
        emit pixmapCreatedOrChanged(imageId, size, handle);
    } else {
        qDebug() << "error";
    }
}

void MLocalThemeDaemon::pixmapHandle(const QString &imageId, const QSize &size)
{
    pixmapHandleSync(imageId, size);
}

void MLocalThemeDaemon::releasePixmap(const QString &imageId, const QSize &size)
{
    if (!daemon.releasePixmap(client, PixmapIdentifier(imageId, size))) {
        qDebug() << "error";
    }
}

QString MLocalThemeDaemon::currentTheme()
{
    return daemon.currentTheme();
}

QStringList MLocalThemeDaemon::themeInheritanceChain()
{
    return daemon.themeInheritanceChain();
}

QStringList MLocalThemeDaemon::themeLibraryNames()
{
    return daemon.themeLibraryNames();
}

bool MLocalThemeDaemon::hasPendingRequests() const
{
    return false;
}

void MLocalThemeDaemon::themeChangedSlot()
{
    QHash<MThemeDaemonClient *, QList<PixmapIdentifier> > pixmapsToReload;
    QList<MThemeDaemonClient *> list;
    list.append(client);

    QList<PixmapCacheEntry*> pixmapsToDelete;
    if (daemon.activateTheme(themeItem.value().toString(), locale.value().toString(), list, pixmapsToDelete)) {
        while (!client->pixmapsToReload.isEmpty()) {
            PixmapIdentifier id = client->pixmapsToReload.takeLast();
            pixmapHandle(id.imageId, id.size);
        }
        // theme change succeeded, let's inform all clients + add the pixmaps to load-list
        emit themeChanged(themeInheritanceChain(), themeLibraryNames());
        qDeleteAll(pixmapsToDelete);
    } else {
        // theme change failed, so change the theme back also in gconf.
        qWarning() << "Could not change theme to" << themeItem.value().toString();
        themeItem.set(currentTheme());
    }
    emit themeChangeCompleted();
}

void MLocalThemeDaemon::localeChanged()
{
    QHash<MThemeDaemonClient *, QList<PixmapIdentifier> > pixmapsToReload;
    QList<MThemeDaemonClient *> clients;
    clients.append(client);
    daemon.changeLocale(locale.value().toString(), clients, pixmapsToReload);

    foreach(const PixmapIdentifier & id, pixmapsToReload[client]) {
        MPixmapHandle handle;
        if (daemon.pixmap(client, id, &handle)) {
            emit pixmapCreatedOrChanged(id.imageId, id.size, handle);
        } else {
            qDebug() << "error";
        }
    }
}

