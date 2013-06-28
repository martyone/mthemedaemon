include(../testapplication.pri)

SOURCES += \
    ut_mimagedirectory.cpp \

HEADERS += \
    ut_mimagedirectory.h \

locale_files.files += ut_mimagedirectory-samples/*
locale_files.path = $$TESTS_DATA_PATH/samples
INSTALLS += locale_files

support_files.files += ut_mimagedirectory-image-svg.svg

check.commands = '\
        TMP_DIR=".ut_mimagedirectory.tmp" \
        && rm -rf \$\${TMP_DIR} \
        && mkdir -p \$\${TMP_DIR} \
        && cp -r $${PWD}/ut_mimagedirectory-samples \$\${TMP_DIR}/samples \
        && cd \$\${TMP_DIR} \
        && export LD_LIBRARY_PATH="$${DESTDIR_LIB}:\$\${LD_LIBRARY_PATH}" \
        && $${OUT_PWD}/$${TARGET}'
