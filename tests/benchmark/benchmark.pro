include(../testapplication.pri)

# Input
SOURCES += benchmarkremoteclient.cpp \
    benchmarklocalclient.cpp \
    main.cpp \
    common.cpp \

HEADERS += benchmarkremoteclient.h \
    benchmarklocalclient.h \
    common.h \

check.commands = '\
        export LD_LIBRARY_PATH="$${DESTDIR_LIB}:\$\${LD_LIBRARY_PATH}" \
        && { ps -C mthemedaemon &>/dev/null \
                || { $${OUT_PWD}/../../src/mthemedaemon & trap "kill \$\$!" EXIT; }; } \
        && sleep 1 \
        && $${OUT_PWD}/$${TARGET}'
