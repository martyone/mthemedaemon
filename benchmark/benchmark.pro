INCLUDEPATH += ../src
DEPENDPATH += $$INCLUDEPATH
TEMPLATE = app
QT += svg \
    network

!win32:CONFIG += link_pkgconfig
PKGCONFIG += x11
PKGCONFIG += mlite

#DEFINES += PRINT_INFO_MESSAGES

# Check for mixing of const and non-const iterators,
# which can cause problems when built with some compilers:
DEFINES += QT_STRICT_ITERATORS

# Input
SOURCES += benchmarkremoteclient.cpp \
    benchmarklocalclient.cpp \
    ../src/mthemedaemon.cpp \
    ../src/mlocalthemedaemon.cpp \
    ../src/mcommonpixmaps.cpp \
    ../src/mimagedirectory.cpp \
    ../src/mthemedaemonclient.cpp \
    ../src/mpixmaphandle.cpp \
    ../src/mthemedaemonprotocol.cpp \
    ../src/mcpumonitor.cpp \
    ../src/mgraphicssystemhelper.cpp \
    ../src/msystemdirectories.cpp \
    main.cpp \
    common.cpp \

HEADERS += benchmarkremoteclient.h \
    benchmarklocalclient.h \
    ../src/mthemedaemon.h \
    ../src/imthemedaemon.h \
    ../src/mlocalthemedaemon.h \
    ../src/mcommonpixmaps.h \
    ../src/mimagedirectory.h \
    ../src/mthemedaemonclient.h \
    ../src/mpixmaphandle.h \
    ../src/mthemedaemonprotocol.h \
    ../src/mcpumonitor.h \
    ../src/mgraphicssystemhelper.h \
    ../src/msystemdirectories.h \
    common.h \

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

target.path = /opt/tests/mthemedaemon
INSTALLS += target
