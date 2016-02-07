include(../../plugins.pri)


HEADERS += decoderopusfactory.h \
    decoder_opus.h \
    opusmetadatamodel.h \
    replaygainreader.h

SOURCES += decoder_opus.cpp \
    decoderopusfactory.cpp \
    opusmetadatamodel.cpp \
    replaygainreader.cpp

TARGET = $$PLUGINS_PREFIX/Input/opus

INCLUDEPATH += ../../../ \
                       $$EXTRA_PREFIX/libopusfile/include \
                       $$EXTRA_PREFIX/libogg/include \
                       $$EXTRA_PREFIX/libtaglib/include

CONFIG += warn_on \
    plugin \
    link_pkgconfig
TEMPLATE = lib
QMAKE_LIBDIR += ../../../../lib

unix {
    isEmpty (LIB_DIR):LIB_DIR = /lib
    target.path = $$LIB_DIR/qmmp/Input
    INSTALLS += target
    LIBS += -L$$EXTRA_PREFIX/libopusfile/lib -lopusfile -lopus \
                  -L$$EXTRA_PREFIX/libtaglib/lib -ltag -lqmmp
    QMAKE_CLEAN = $$PLUGINS_PREFIX/Input/libopus.so
}

win32 {
    HEADERS += ../../../../src/qmmp/metadatamodel.h \
               ../../../../src/qmmp/decoderfactory.h
    QMAKE_LIBDIR += ../../../../bin
    gcc{
        LIBS += -L$$EXTRA_PREFIX/libopusfile/lib -lopusfile -lopus \
                      -L$$EXTRA_PREFIX/libtaglib/lib -ltag.dll \
                      -lqmmp0 -lm
    }
#    LIBS += -lqmmp0 -lopusfile -lopus -ltag.dll -lm
}
