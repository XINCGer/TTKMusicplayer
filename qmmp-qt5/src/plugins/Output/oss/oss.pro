include(../../plugins.pri)


HEADERS += outputossfactory.h \
           outputoss.h



SOURCES += outputossfactory.cpp \
           outputoss.cpp


TARGET=$$PLUGINS_PREFIX/Output/oss
QMAKE_CLEAN =$$PLUGINS_PREFIX/Output/liboss.so


INCLUDEPATH += ../../../
QMAKE_LIBDIR += ../../../../lib
CONFIG += warn_on \
thread \
plugin

DEFINES += HAVE_SYS_SOUNDCARD_H

TEMPLATE = lib
LIBS += -lqmmp


isEmpty (LIB_DIR){
LIB_DIR = /lib
}

target.path = $$LIB_DIR/qmmp/Output
INSTALLS += target
