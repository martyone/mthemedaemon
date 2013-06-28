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

check.commands = '\
        TMP_DIR=".stresstest.tmp" \
        && rm -rf \$\${TMP_DIR} \
        && mkdir -p \$\${TMP_DIR} \
        && cp -r $${PWD}/themes \$\${TMP_DIR}/ \
        && cd \$\${TMP_DIR} \
        && export PATH="$${OUT_PWD}/../../src:\$\${PATH}" \
        && export LD_LIBRARY_PATH="$${DESTDIR_LIB}:\$\${LD_LIBRARY_PATH}" \
        && $${OUT_PWD}/$${TARGET} 10'
