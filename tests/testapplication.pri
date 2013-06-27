include(tests_common.pri)
include(../src/mthemedaemonlib.pri)

TEMPLATE = app

QT += testlib

SUBPROJECT_NAME = $$basename(_PRO_FILE_)
SUBPROJECT_NAME ~= s/\\.pro$//


target.path = $$TESTS_PATH
INSTALLS += target

TESTS_DATA_PATH = $${TESTS_PATH}/data/$${SUBPROJECT_NAME}

support_files.path = $$TESTS_DATA_PATH
INSTALLS += support_files
