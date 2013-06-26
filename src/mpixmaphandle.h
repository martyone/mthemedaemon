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

#include <qnamespace.h>
#include <QMetaType>
#include <QString>
#include <QSize>
#include <QImage>

#ifndef MPIXMAPHANDLE_H
#define MPIXMAPHANDLE_H

struct MPixmapHandle
{
    MPixmapHandle();

    bool isValid() const;

    Qt::HANDLE xHandle;
    Qt::HANDLE eglHandle;
    QByteArray shmHandle;
    QSize size;
    QImage::Format format;
    int numBytes;

    bool directMap;
};

Q_DECLARE_METATYPE(MPixmapHandle)

#endif //MPIXMAPHANDLE_H
