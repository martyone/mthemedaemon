include(../common.pri)
include(mthemedaemonlib_dependencies.pri)

TEMPLATE = lib
CONFIG(release, debug|release):CONFIG += static
TARGET = mthemedaemonlib
DESTDIR = $${DESTDIR_LIB}

DEFINES += MTHEME_PRINT_DEBUG

# Input
SOURCES = \
    logger.cpp \
    mcommonpixmaps.cpp \
    mcpumonitor.cpp \
    mgraphicssystemhelper.cpp \
    mimagedirectory.cpp \
    mlocalthemedaemon.cpp \
    mpixmaphandle.cpp \
    mremotethemedaemon.cpp \
    msystemdirectories.cpp \
    mthemedaemonclient.cpp \
    mthemedaemon.cpp \
    mthemedaemonprotocol.cpp \
    mthemedaemonserver.cpp \

HEADERS = \
    imthemedaemon.h \
    keypresswaiter.h \
    logger.h \
    mcommonpixmaps.h \
    mcpumonitor.h \
    mgraphicssystemhelper.h \
    mimagedirectory.h \
    mlocalthemedaemon.h \
    mpixmaphandle.h \
    mremotethemedaemon.h \
    mremotethemedaemon_p.h \
    msystemdirectories.h \
    mthemedaemonclient.h \
    mthemedaemon.h \
    mthemedaemonprotocol.h \
    mthemedaemonserver.h \

linux* {
    HEADERS += \
        inotify.h \
        inotify.watch.h \
        fstreenode.h \
        utils.h \

    SOURCES += \
        inotify.cpp \
        inotify.watch.cpp \
        fstreenode.cpp \
        utils.cpp \
}
