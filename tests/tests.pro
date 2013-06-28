include(tests_common.pri)

TEMPLATE = subdirs
SUBDIRS = \
        benchmark \
        stresstest \
        ut_mcommonpixmaps \
        ut_mimagedirectory \
        ut_mthemedaemonprotocol \

for(subdir, SUBDIRS): eval($${subdir}.depends = utils)
SUBDIRS += utils

tests_xml.files = benchmark-tests.xml unit-tests.xml
tests_xml.path = $$TESTS_PATH
INSTALLS += tests_xml
