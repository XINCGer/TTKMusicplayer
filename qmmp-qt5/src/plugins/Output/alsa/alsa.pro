include(../../plugins.pri)

HEADERS += outputalsa.h \
           outputalsafactory.h  \


SOURCES += outputalsa.cpp \
           outputalsafactory.cpp


TARGET=$$PLUGINS_PREFIX/Output/alsa
QMAKE_CLEAN =$$PLUGINS_PREFIX/Output/libalsa.so

INCLUDEPATH += ../../../
QMAKE_LIBDIR += ../../../../lib

CONFIG += warn_on \
thread \
plugin \
link_pkgconfig

TEMPLATE = lib
LIBS += -lqmmp
INCLUDEPATH += $$EXTRA_PREFIX/libalsa/include
LIBS += -L$$EXTRA_PREFIX/libalsa/lib -lasound \
             -lqmmp

isEmpty (LIB_DIR){
LIB_DIR = /lib
}

target.path = $$LIB_DIR/qmmp/Output
INSTALLS += target
