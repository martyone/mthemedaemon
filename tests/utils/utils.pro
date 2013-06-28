include(../tests_common.pri)
include(utils_dependencies.pri)

TEMPLATE = lib
TARGET = utils
DESTDIR = $$DESTDIR_LIB

SOURCES = \
    mlocalthemedaemon.cpp \
    mremotethemedaemon.cpp \

HEADERS = \
    imthemedaemon.h \
    mlocalthemedaemon.h \
    mremotethemedaemon.h \
    mremotethemedaemon_p.h \

target.path = $$TESTS_PATH
INSTALLS += target
