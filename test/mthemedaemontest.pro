include(../common.pri)
include(../src/mthemedaemonlib.pri)

TEMPLATE = app
TARGET = mthemedaemontest.bin

# Input
SOURCES += main.cpp \
           clientmanager.cpp \
           testclient.cpp \

HEADERS += clientmanager.h \
           testclient.h \

target.path = $$TESTS_PATH
INSTALLS += target

wrapper.files = mthemedaemontest
wrapper.path = $$TESTS_PATH
INSTALLS += wrapper

themes.files = themes
themes.path = $$TESTS_PATH
INSTALLS += themes
