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

#ifndef KEYPRESSWAITER_H
#define KEYPRESSWAITER_H

#include <QApplication>
#include <QThread>
#include <QTextStream>
#include <QFile>
#include <QtDebug>

class KeyPressWaiter : public QThread
{
    Q_OBJECT
public:

    void run() {
        QTextStream(stdout) << "Hit enter to exit..." << endl;
        QTextStream qin(stdin, QFile::ReadOnly);
        qin.readLine();
    }
};

#endif
