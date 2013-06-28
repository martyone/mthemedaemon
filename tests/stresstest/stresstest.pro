include(../testapplication.pri)

# Input
SOURCES += main.cpp \
           clientmanager.cpp \
           testclient.cpp \

HEADERS += clientmanager.h \
           testclient.h \

themes.files = themes
themes.path = $$TESTS_DATA_PATH
INSTALLS += themes
