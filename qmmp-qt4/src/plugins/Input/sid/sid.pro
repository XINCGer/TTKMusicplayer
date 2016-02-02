include(../../plugins.pri)

HEADERS += decodersidfactory.h \
    decoder_sid.h \
    sidhelper.h \
    settingsdialog.h
SOURCES += decoder_sid.cpp \
    decodersidfactory.cpp \
    sidhelper.cpp \
    settingsdialog.cpp
FORMS += \
    settingsdialog.ui


TARGET = $$PLUGINS_PREFIX/Input/sid
QMAKE_CLEAN = $$PLUGINS_PREFIX/Input/libsid.so
INCLUDEPATH += ../../../
CONFIG += warn_on \
          plugin \
          link_pkgconfig
TEMPLATE = lib

unix{
    isEmpty (LIB_DIR):LIB_DIR = /lib
    target.path = $$LIB_DIR/qmmp/Input
    INSTALLS += target
    QMAKE_LIBDIR += ../../../../lib
    LIBS += -lqmmp
    PKGCONFIG += libsidplayfp
}

win32 {
    HEADERS += ../../../../src/qmmp/metadatamodel.h \
               ../../../../src/qmmp/decoderfactory.h
    QMAKE_LIBDIR += ../../../../bin

    gcc{
        INCLUDEPATH += $$EXTRA_PREFIX/libsidplayfp/include

        LIBS += -lqmmp0 \
                -L$$EXTRA_PREFIX/libsidplayfp/lib -lsidplayfp.dll \

    }
#    LIBS += -lqmmp0 -lsidplayfp.dll
}
