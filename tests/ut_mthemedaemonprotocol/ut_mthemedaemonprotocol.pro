include(../testapplication.pri)

SOURCES += \
    ut_mthemedaemonprotocol.cpp \

HEADERS += \
    ut_mthemedaemonprotocol.h \

check.commands = '\
        export LD_LIBRARY_PATH="$${DESTDIR_LIB}:\$\${LD_LIBRARY_PATH}" \
        && $${OUT_PWD}/$${TARGET}'
