!win32:CONFIG += link_pkgconfig
PKGCONFIG += x11
PKGCONFIG += mlite

# TODO: fix header files to use forward declarations and move this to mthemedaemonlib.pro
QT += svg network
