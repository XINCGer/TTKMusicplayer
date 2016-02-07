include(../../plugins.pri)

HEADERS += decodersndfilefactory.h \
           decoder_sndfile.h
SOURCES += decoder_sndfile.cpp \
           decodersndfilefactory.cpp

TARGET=$$PLUGINS_PREFIX/Input/sndfile


INCLUDEPATH += ../../../ \
                   $$EXTRA_PREFIX/libsndfile/include \
                   $$EXTRA_PREFIX/libflac/include \
                   $$EXTRA_PREFIX/libvorbis/include \
                   $$EXTRA_PREFIX/libogg/include

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
    LIBS += -L$$EXTRA_PREFIX/libsndfile/lib -lsndfile \
            -L$$EXTRA_PREFIX/libflac/lib -lFLAC \
            -L$$EXTRA_PREFIX/libvorbis/lib -lvorbisenc -lvorbis \
            -L$$EXTRA_PREFIX/libogg/lib -logg \
            -lqmmp
    QMAKE_CLEAN =$$PLUGINS_PREFIX/Input/libsndfile.so
}

win32 {
    HEADERS += ../../../../src/qmmp/metadatamodel.h \
               ../../../../src/qmmp/decoderfactory.h
    QMAKE_LIBDIR += ../../../../bin
    gcc{
        LIBS += -L$$EXTRA_PREFIX/libsndfile/lib -lsndfile \
                -L$$EXTRA_PREFIX/libflac/lib -lflac \
                -L$$EXTRA_PREFIX/libvorbis/lib -lvorbisenc -lvorbis \
                -L$$EXTRA_PREFIX/libogg/lib -logg \
                -lqmmp1
    }
#    LIBS += -lqmmp0 -lsndfile -lflac -lvorbisenc -lvorbis -logg
}
