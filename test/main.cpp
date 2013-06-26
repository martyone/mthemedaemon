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

#include <QDebug>
#include <QApplication>
#include <QDir>
#include <MGConfItem>
#include "mthemedaemon.h"
#include "keypresswaiter.h"
#include "clientmanager.h"

int main(int argc, char **argv)
{
    srand(time(0));
    QApplication app(argc, argv);

    const QString themeName = "theme_one";
    MGConfItem theme("/meegotouch/theme/name");
    theme.set(themeName);

    bool result = false;
    QProcess td;
    QProcessEnvironment environment = QProcessEnvironment::systemEnvironment();
    environment.insert("MTHEMEDAEMON_THEME_DIRECTORY",
            QDir().absoluteFilePath(THEME_ROOT_DIRECTORY));
    td.setProcessEnvironment(environment);
    td.start("./testdaemon/testdaemon", QStringList()
            << "-address" << "/tmp/mthemedaemon-tests.socket");
    // start theme daemon
    if (td.waitForStarted()) {
        // This is the class that handles the test
        ClientManager manager(td);

        // close on enter
        KeyPressWaiter keyWaiter;
        QObject::connect(&keyWaiter, SIGNAL(finished()), &manager, SLOT(stop()));
        keyWaiter.start();

        // event loop
        result = app.exec();

        // stop theme daemon
        if (td.state() == QProcess::Running) {
            td.close();
        }
    } else {
        qWarning() << "Theme daemon failed to start";
    }

    theme.unset();

    return result;
}
