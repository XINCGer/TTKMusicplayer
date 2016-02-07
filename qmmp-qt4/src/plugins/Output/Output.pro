include(../../../qmmp.pri)

TEMPLATE = subdirs
win32:{
    SUBDIRS += waveout directsound
}

SUBDIRS += null

unix{
    contains(CONFIG, ALSA_PLUGIN){
        SUBDIRS += alsa
    }
}
