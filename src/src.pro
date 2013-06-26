TEMPLATE = app
TARGET = mthemedaemon

QT += svg network

contains(DEFINES, HAVE_MEEGOGRAPHICSSYSTEM) {
    QT += meegographicssystemhelper
}

DEFINES += MTHEME_PRINT_DEBUG
#DEFINES += CLOSE_ON_ENTER

# enable QString optimizations
DEFINES += QT_USE_FAST_CONCATENATION QT_USE_FAST_OPERATOR_PLUS

# Check for mixing of const and non-const iterators, 
# which can cause problems when built with some compilers:
DEFINES += QT_STRICT_ITERATORS

!win32:CONFIG += link_pkgconfig
PKGCONFIG += x11
PKGCONFIG += mlite
PKGCONFIG += libsystemd-daemon

# Input
SOURCES += main.cpp \
           mthemedaemonserver.cpp \
           mthemedaemon.cpp \
           mcommonpixmaps.cpp \
           mimagedirectory.cpp \
           mthemedaemonclient.cpp \
           mpixmaphandle.cpp \
           mthemedaemonprotocol.cpp \
           mcpumonitor.cpp \
           mgraphicssystemhelper.cpp \
           msystemdirectories.cpp \
           logger.cpp

HEADERS += \
           mthemedaemonserver.h \
           mthemedaemon.h \
           mcommonpixmaps.h \
           mimagedirectory.h \
           mpixmaphandle.h \
           mthemedaemonclient.h \
           mthemedaemonprotocol.h \
           mcpumonitor.h \
           mgraphicssystemhelper.h \
           msystemdirectories.h \
           keypresswaiter.h \
           logger.h

linux* {
    HEADERS += inotify.h \
               inotify.watch.h \
               fstreenode.h \
               utils.h
    SOURCES += inotify.cpp \
               inotify.watch.cpp \
               fstreenode.cpp \
               utils.cpp
}

target.path = /usr/bin
INSTALLS += target

themedaemonpriorities.files = themedaemonpriorities.conf
themedaemonpriorities.path = /etc/meegotouch
INSTALLS += themedaemonpriorities
