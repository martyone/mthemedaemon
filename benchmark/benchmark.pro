include(../common.pri)
include(../src/mthemedaemonlib.pri)

TEMPLATE = app

# Input
SOURCES += benchmarkremoteclient.cpp \
    benchmarklocalclient.cpp \
    main.cpp \
    common.cpp \

HEADERS += benchmarkremoteclient.h \
    benchmarklocalclient.h \
    common.h \

target.path = $$TESTS_PATH
INSTALLS += target
