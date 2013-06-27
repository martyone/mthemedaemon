contains(DEFINES, HAVE_MEEGOGRAPHICSSYSTEM) {
    QT += meegographicssystemhelper
}

#DEFINES += PRINT_INFO_MESSAGES

# Check for mixing of const and non-const iterators,
# which can cause problems when built with some compilers:
DEFINES += QT_STRICT_ITERATORS

# enable QString optimizations
DEFINES += QT_USE_FAST_CONCATENATION QT_USE_FAST_OPERATOR_PLUS

# TODO: determine build dir automatically
MTHEMEDAEMON_BUILD_DIR = $$PWD/build

DESTDIR_LIB = $$MTHEMEDAEMON_BUILD_DIR/lib

LIBS += -L$$DESTDIR_LIB

TESTS_PATH = "/opt/tests/mthemedaemon"
