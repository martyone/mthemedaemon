INCLUDEPATH += ../src
DEPENDPATH += $$INCLUDEPATH
TEMPLATE = app
TARGET = mthemedaemontest.bin

QT += svg network

!win32:CONFIG += link_pkgconfig
PKGCONFIG += x11
PKGCONFIG += mlite

# Input
SOURCES += main.cpp \
           clientmanager.cpp \
           testclient.cpp \
           ../src/mremotethemedaemon.cpp \
           ../src/mpixmaphandle.cpp \
           ../src/mthemedaemonprotocol.cpp \

HEADERS += clientmanager.h \
           testclient.h \
           ../src/keypresswaiter.h \
           ../src/mremotethemedaemon.h \
           ../src/imthemedaemon.h \
           ../src/mpixmaphandle.h \
           ../src/mthemedaemonprotocol.h \

target.path = /opt/tests/mthemedaemon
INSTALLS += target

wrapper.files = mthemedaemontest
wrapper.path = /opt/tests/mthemedaemon
INSTALLS += wrapper

themes.files = themes
themes.path = /opt/tests/mthemedaemon
INSTALLS += themes
