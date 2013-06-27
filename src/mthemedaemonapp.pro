include(../common.pri)
include(mthemedaemonlib.pri)

TEMPLATE = app
TARGET = mthemedaemon

PKGCONFIG += libsystemd-daemon

#DEFINES += CLOSE_ON_ENTER

SOURCES = \
    main.cpp \

target.path = /usr/bin
INSTALLS += target

themedaemonpriorities.files = themedaemonpriorities.conf
themedaemonpriorities.path = /etc/meegotouch
INSTALLS += themedaemonpriorities
