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

#ifndef MTHEMEDAEMON_H
#define MTHEMEDAEMON_H
//This is setuping base as the default theme for themedaemon if a wrong/emtpy value is at gconf key
#define M_THEME_DEFAULT "base"

#include <QObject>
#include "mthemedaemonprotocol.h"
#include "mcommonpixmaps.h"

class MThemeDaemonClient;

class MThemeImagesDirectory;

//! \internal
class MThemeDaemon
{
public:
    enum Type {
        LocalDaemon = 0,
        RemoteDaemon = 1
    };

#ifndef NOIMAGEDIRECTORIES
    MThemeDaemon(Type type);
    virtual ~MThemeDaemon();
#endif

    static QString systemThemeDirectory();
    static QString systemThemeCacheDirectory();

#ifndef NOIMAGEDIRECTORIES
    void addClient(MThemeDaemonClient *client);
    void removeClient(MThemeDaemonClient *client);

    bool pixmap(MThemeDaemonClient *client, const M::MThemeDaemonProtocol::PixmapIdentifier &id, MPixmapHandle *handle);
    bool releasePixmap(MThemeDaemonClient *client, const M::MThemeDaemonProtocol::PixmapIdentifier &id);

    bool activateTheme(const QString &newTheme, const QString &locale, const QList<MThemeDaemonClient *>& clientList, QList<PixmapCacheEntry*>& pixmapsToDelete, bool forceReload = false);

    void changeLocale(const QString &newLocale, const QList<MThemeDaemonClient *>& clientList, QHash<MThemeDaemonClient *, QList<M::MThemeDaemonProtocol::PixmapIdentifier> >& pixmapsToReload);

    QStringList themeInheritanceChain() const;
    QStringList themeLibraryNames() const;

    QString currentTheme() const;

    ImageResource *findImageResource(const QString &imageId);

    MCommonPixmaps mostUsedPixmaps;
    /*! Print out requested graphics IDs and files which are used */
    static bool printGraphicalFiles;

private:

    void reloadImagePaths(const QString &locale, bool forceReload);
private:
    QString currentThemeName;
    QStringList themeInheritance;
    QStringList themeLibraries;
    QList<MThemeImagesDirectory *> themeImageDirs;
    Type type;
#else
private:
    MThemeDaemon( ); // just make sure nobody tries to construct broken class
#endif

    friend class Ut_MCommonPixmaps;
};
//! \internal_end
#endif

