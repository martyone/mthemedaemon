INCLUDEPATH += ../src
DEPENDPATH += $$INCLUDEPATH
TEMPLATE = app
TARGET = mthemedaemontest.bin

QT += svg network

!win32:CONFIG += link_pkgconfig
PKGCONFIG += x11
PKGCONFIG += mlite

# override theme directory
DEFINES += IMAGESDIR=\\\"./images\\\"

# we want to be able to access private classes
DEFINES += UNIT_TEST

# Input
SOURCES += main.cpp \
           clientmanager.cpp \
           testclient.cpp \
           ../src/mremotethemedaemon.cpp \
           ../src/mthemedaemon.cpp \
           ../src/mcommonpixmaps.cpp \
           ../src/mimagedirectory.cpp \
           ../src/mthemedaemonclient.cpp \
           ../src/mpixmaphandle.cpp \
           ../src/mthemedaemonprotocol.cpp \
           ../src/mcpumonitor.cpp \
           ../src/mgraphicssystemhelper.cpp \
           ../src/msystemdirectories.cpp \

HEADERS += clientmanager.h \
           testclient.h \
           ../src/keypresswaiter.h \
           ../src/mremotethemedaemon.h \
           ../src/imthemedaemon.h \
           ../src/mthemedaemon.h \
           ../src/mcommonpixmaps.h \
           ../src/mimagedirectory.h \
           ../src/mthemedaemonclient.h \
           ../src/mpixmaphandle.h \
           ../src/mthemedaemonprotocol.h \
           ../src/mcpumonitor.h \
           ../src/mgraphicssystemhelper.h \
           ../src/msystemdirectories.h \

linux* {
    HEADERS += ../src/inotify.h \
               ../src/inotify.watch.h \
               ../src/fstreenode.h \
               ../src/utils.h
    SOURCES += ../src/inotify.cpp \
               ../src/inotify.watch.cpp \
               ../src/fstreenode.cpp \
               ../src/utils.cpp
}

SUBDIRS += testdaemodrgtrgn

target.path = /opt/tests/mthemedaemon
INSTALLS += target

wrapper.files = mthemedaemontest
wrapper.path = /opt/tests/mthemedaemon
INSTALLS += wrapper

themes.files = themes
themes.path = /opt/tests/mthemedaemon
INSTALLS += themes
