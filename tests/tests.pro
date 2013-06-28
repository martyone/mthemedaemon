include(tests_common.pri)

TEMPLATE = subdirs
SUBDIRS = \
        benchmark \
        stresstest \
        ut_mthemedaemonprotocol \

tests_xml.files = tests.xml
tests_xml.path = $$TESTS_PATH
INSTALLS += tests_xml
