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
#include "mpixmaphandle.h"

MPixmapHandle::MPixmapHandle() :
    xHandle(0),
    eglHandle(0),
    shmHandle(QByteArray()),
    format(QImage::Format_Invalid),
    numBytes(0),
    directMap(false)
{
    qRegisterMetaType<MPixmapHandle>();
}

bool MPixmapHandle::isValid() const
{
    return (!size.isEmpty() && eglHandle && !shmHandle.isEmpty()) ^ (unsigned long)xHandle;
}

