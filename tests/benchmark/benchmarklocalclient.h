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
#ifndef BENCHMARKLOCALCLIENT_H
#define BENCHMARKLOCALCLIENT_H

#include <QObject>

class BenchmarkLocalClient : public QObject
{
    Q_OBJECT
public:
    BenchmarkLocalClient();

signals:
    void finished();

public slots:
    void run();
};

#endif // BENCHMARKLOCALCLIENT_H
