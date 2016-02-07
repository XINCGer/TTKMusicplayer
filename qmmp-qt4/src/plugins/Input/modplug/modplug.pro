include(../../plugins.pri)

HEADERS += decodermodplugfactory.h \
    decoder_modplug.h \
    archivereader.h \
    modplugmetadatamodel.h


SOURCES += decoder_modplug.cpp \
    decodermodplugfactory.cpp \
    archivereader.cpp \
    modplugmetadatamodel.cpp


TARGET = $$PLUGINS_PREFIX/Input/modplug

DEFINES += HAVE_STDINT_H \
    HAVE_INTTYPES_H

INCLUDEPATH += ../../../ \
                    $$EXTRA_PREFIX/libmodplug/include

CONFIG += warn_on \
    plugin \
    link_pkgconfig
TEMPLATE = lib
QMAKE_LIBDIR += ../../../../lib



unix {
    isEmpty(LIB_DIR):LIB_DIR = /lib
    target.path = $$LIB_DIR/qmmp/Input
    INSTALLS += target
    QMAKE_LIBDIR += ../../../../lib
    LIBS += -L$$EXTRA_PREFIX/libmodplug/lib -lmodplug -lqmmp
    QMAKE_CLEAN = $$PLUGINS_PREFIX/Input/libmodplug.so
}

win32 {
    HEADERS += ../../../../src/qmmp/metadatamodel.h \
               ../../../../src/qmmp/decoderfactory.h
    QMAKE_LIBDIR += ../../../../bin
    gcc{
        LIBS += -L$$EXTRA_PREFIX/libmodplug/lib -lmodplug \
                -lqmmp0
    }
#    LIBS += -lqmmp0 -lmodplug
    DEFINES -= UNICODE
}
