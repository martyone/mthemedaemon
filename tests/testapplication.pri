include(tests_common.pri)
include(utils/utils.pri)
include(../src/mthemedaemonlib.pri)

TEMPLATE = app

QT += testlib

SUBPROJECT_NAME = $$basename(_PRO_FILE_)
SUBPROJECT_NAME ~= s/\\.pro$//

TARGET = $${SUBPROJECT_NAME}.bin

target.path = $$TESTS_PATH
INSTALLS += target

wrapper.files = $${SUBPROJECT_NAME}
wrapper.path = $$TESTS_PATH
INSTALLS += wrapper

TESTS_DATA_PATH = $${TESTS_PATH}/data/$${SUBPROJECT_NAME}

support_files.path = $$TESTS_DATA_PATH
INSTALLS += support_files

check.depends = all
check.commands = false "Please override check.command in $${_PRO_FILE_}"
check.CONFIG = phony
QMAKE_EXTRA_TARGETS += check
