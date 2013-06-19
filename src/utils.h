/***************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation
** and appearing in the file LICENSE.LGPL included in the packaging
** of this file.
**
****************************************************************************/

#ifndef __UTIL_HH__
#define __UTIL_HH__


// TODO: figure what to do with these ...


namespace util
{     // the only purpose of this function is using new (and avoiding using C free() )
    char *dup(const char *src);

    void rewindbuf(unsigned char *buffer, unsigned amount, unsigned buflength);

      // Allocates char array containing filename cut from last dot. Sets
      // lastdot to point to part of filename that was cut away from basename.
      // Can return 0 (and set lastdot to 0) in which case no allocation was
      // made.
    char *basename(const char *filename, const char *&lastdot);
}


#endif // __UTIL_HH__

