include(../testapplication.pri)

TARGET = ut_mimagedirectory.bin

SOURCES += \
    ut_mimagedirectory.cpp \

HEADERS += \
    ut_mimagedirectory.h \

wrapper.files = ut_mimagedirectory
wrapper.path = $$TESTS_PATH
INSTALLS += wrapper

locale_files.files += ut_mimagedirectory-samples/*
locale_files.path = $$TESTS_DATA_PATH/samples
INSTALLS += locale_files

support_files.files += ut_mimagedirectory-image-svg.svg
