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
#include <QTimer>
#include <MGConfItem>
#include "keypresswaiter.h"
#include "clientmanager.h"

int main(int argc, char **argv)
{
    srand(time(0));
    QApplication app(argc, argv);

    const QString themeName = "theme_one";
    MGConfItem theme("/meegotouch/theme/name");
    theme.set(themeName);

    ClientManager::setup();

    bool result = false;
    QProcess td;
    QProcessEnvironment environment = QProcessEnvironment::systemEnvironment();
    environment.insert("MTHEMEDAEMON_UNIT_TEST_RUN", "1");
    environment.insert("MTHEMEDAEMON_THEME_DIRECTORY",
            QDir().absoluteFilePath(THEME_ROOT_DIRECTORY));
    td.setProcessEnvironment(environment);
    td.start("mthemedaemon", QStringList()
            << "-address" << "/tmp/mthemedaemon-tests.socket");
    // start theme daemon
    if (td.waitForStarted()) {
        // This is the class that handles the test
        ClientManager manager(td);

        // close on enter
        KeyPressWaiter keyWaiter;
        QObject::connect(&keyWaiter, SIGNAL(finished()), &manager, SLOT(stop()));
        keyWaiter.start();

        // close on timeout
        if (app.arguments().count() == 2) {
            bool ok;
            int delay;
            if (delay = app.arguments().at(1).toInt(&ok), !ok || delay <= 0) {
                qWarning() << "Usage: $0 [seconds]";
                return 1;
            }

            QTextStream(stdout) << "Will run for " << delay << " seconds..." << endl;

            // terminate keyWaiter instead of directly invoking manager->stop() to prevent QThread
            // issuing a warning about being destroyed while running.
            QTimer::singleShot(delay * 1000, &keyWaiter, SLOT(terminate()));
        }

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

    ClientManager::cleanup();

    return result;
}
