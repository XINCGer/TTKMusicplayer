include(../../plugins.pri)


HEADERS += decoderffmpegfactory.h \
    decoder_ffmpeg.h \
    ffmpegmetadatamodel.h


SOURCES += decoder_ffmpeg.cpp \
    decoderffmpegfactory.cpp \
    ffmpegmetadatamodel.cpp

INCLUDEPATH += ../../../ \
                $$EXTRA_PREFIX/libav/include

CONFIG += warn_on \
    plugin \
    link_pkgconfig
TEMPLATE = lib

TARGET = $$PLUGINS_PREFIX/Input/ffmpeg_legacy

unix {
    isEmpty(LIB_DIR):LIB_DIR = /lib
    target.path = $$LIB_DIR/qmmp/Input
    INSTALLS += target
    QMAKE_CLEAN = $$PLUGINS_PREFIX/Input/libffmpeg.so
    LIBS += -L$$EXTRA_PREFIX/libav/lib -lavcodec -lavformat -lavutil -lqmmp
    QMAKE_LIBDIR += ../../../../lib
}

win32 {
    HEADERS += ../../../../src/qmmp/metadatamodel.h \
               ../../../../src/qmmp/decoderfactory.h
    QMAKE_LIBDIR += ../../../../bin
    gcc{
        LIBS += -L$$EXTRA_PREFIX/libav/lib -lavcodec.dll -lavformat.dll -lavutil.dll \
                -lqmmp1
    }
#    LIBS += -lqmmp0 -lavcodec.dll -lavformat.dll -lavutil.dll
}

DEFINES += __STDC_CONSTANT_MACROS



