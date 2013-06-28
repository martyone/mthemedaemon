include(../testapplication.pri)

SOURCES += \
    ut_mimagedirectory.cpp \

HEADERS += \
    ut_mimagedirectory.h \

locale_files.files += ut_mimagedirectory-samples/*
locale_files.path = $$TESTS_DATA_PATH/samples
INSTALLS += locale_files

support_files.files += ut_mimagedirectory-image-svg.svg
