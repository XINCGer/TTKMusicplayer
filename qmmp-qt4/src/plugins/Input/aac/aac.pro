include(../../plugins.pri)
FORMS +=
HEADERS += decoderaacfactory.h \
    decoder_aac.h \
    aacfile.h \
    aacmetadatamodel.h
SOURCES += decoder_aac.cpp \
    decoderaacfactory.cpp \
    aacfile.cpp \
    aacmetadatamodel.cpp
TARGET = $$PLUGINS_PREFIX/Input/aac
QMAKE_CLEAN = $$PLUGINS_PREFIX/Input/libaac.so
INCLUDEPATH += ../../../
CONFIG += warn_on \
    plugin \
    link_pkgconfig
TEMPLATE = lib

win32:{
  QMAKE_LIBDIR += ../../../../bin
  gcc{
      INCLUDEPATH += $$EXTRA_PREFIX/libfaad2/include \
                     $$EXTRA_PREFIX/libtaglib/include
      LIBS += -L$$EXTRA_PREFIX/libfaad2/lib -lfaad \
              -L$$EXTRA_PREFIX/libtaglib/lib -ltag.dll \
              -lqmmp0
  }
}
unix:{
    QMAKE_LIBDIR += ../../../../lib
    LIBS += -lqmmp \
        -lfaad \
        -L/usr/lib \
        -I/usr/include

    PKGCONFIG += taglib
}

isEmpty(LIB_DIR):LIB_DIR = /lib
target.path = $$LIB_DIR/qmmp/Input
INSTALLS += target
