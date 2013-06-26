include(../common.pri)

TEMPLATE = subdirs

SUBDIRS = mthemedaemontest.pro \

tests_xml.files = tests.xml
tests_xml.path = $$TESTS_PATH
INSTALLS += tests_xml
