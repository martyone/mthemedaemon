include(../testapplication.pri)

SOURCES += \
    ut_mcommonpixmaps.cpp \

HEADERS += \
    ut_mcommonpixmaps.h \

support_files.files += svg

check.commands = '\
        TMP_DIR="data/ut_mcommonpixmaps" \
        && rm -rf \$\${TMP_DIR} \
        && mkdir -p \$\${TMP_DIR} \
        && cp -r $${PWD}/svg \$\${TMP_DIR}/ \
        && export LD_LIBRARY_PATH="$${DESTDIR_LIB}:\$\${LD_LIBRARY_PATH}" \
        && $${OUT_PWD}/$${TARGET}'
