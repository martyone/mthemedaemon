include(../testapplication.pri)

TARGET = stresstest.bin

# Input
SOURCES += main.cpp \
           clientmanager.cpp \
           testclient.cpp \

HEADERS += clientmanager.h \
           testclient.h \

wrapper.files = stresstest
wrapper.path = $$TESTS_PATH
INSTALLS += wrapper

themes.files = themes
themes.path = $$TESTS_DATA_PATH
INSTALLS += themes
