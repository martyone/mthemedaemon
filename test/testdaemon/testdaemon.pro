TEMPLATE = app
DEPENDPATH += .

QT += svg network

#DEFINES += MTHEME_PRINT_DEBUG
#DEFINES += CLOSE_ON_ENTER


DEFINES ~= s/THEMEDIR.*/THEMEDIR=\\\"\"themes\"\\\"/

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
SOURCES += ../../src/main.cpp \
           ../../src/mthemedaemonserver.cpp \
           ../../src/mthemedaemon.cpp \
           ../../src/mcommonpixmaps.cpp \
           ../../src/mimagedirectory.cpp \
           ../../src/mthemedaemonclient.cpp \
           ../../src/mthemedaemonprotocol.cpp \
           ../../src/mpixmaphandle.cpp \
           ../../src/mcpumonitor.cpp \
           ../../src/mgraphicssystemhelper.cpp \
           ../../src/msystemdirectories.cpp \
           ../../src/logger.cpp \

HEADERS += \
           ../../src/mthemedaemonserver.h \
           ../../src/mthemedaemon.h \
           ../../src/mcommonpixmaps.h \
           ../../src/mimagedirectory.h \
           ../../src/mthemedaemonclient.h \
           ../../src/mthemedaemonprotocol.h \
           ../../src/mpixmaphandle.h \
           ../../src/mcpumonitor.h \
           ../../src/mgraphicssystemhelper.h \
           ../../src/msystemdirectories.h \
           ../../src/logger.h \

linux* {
    HEADERS += ../../src/inotify.h \
               ../../src/inotify.watch.h \
               ../../src/fstreenode.h \
               ../../src/utils.h
    SOURCES += ../../src/inotify.cpp \
               ../../src/inotify.watch.cpp \
               ../../src/fstreenode.cpp \
               ../../src/utils.cpp
}

target.path = /opt/tests/mthemedaemon/testdaemon
INSTALLS += target
