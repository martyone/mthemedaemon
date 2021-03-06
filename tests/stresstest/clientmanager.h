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

#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <QObject>
#include <QPointer>
#include <QProcess>
#include <QSet>
#include <QSize>
#include "mpixmaphandle.h"

class ClientThread;
class TestClient;

static const QString THEME_ROOT_DIRECTORY = QString("themes");

class ClientManager : public QObject
{
    Q_OBJECT

    static const int MAX_CLIENT_COUNT = 10;

public:
    ClientManager(QProcess &process);
    ~ClientManager();

    static ClientManager *instance();

    void stop(bool error);

    static void cleanup();
    static void setup();

protected:
    void spawnClient();

private slots:
    void start();
    void stop();

    void checkConsistency();

    void clientStarted();
    void clientFinished();
    void changeThemeAndLocale();

    void pixmapReady(const QString& theme, TestClient* client, const MPixmapHandle &handle, const QString& imageId, const QSize& size);

private:
    bool verifyPixmap(const QString& theme, TestClient* client, const MPixmapHandle &handle, const QString& imageId, const QSize& size);

    static const QStringList locales;
    QSet<ClientThread *> clients;
    bool shutdown;
    QProcess &themedaemon;
    bool error;
    static QPointer<ClientManager> s_instance;
};

#endif
