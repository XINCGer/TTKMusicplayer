# =================================================
# * This file is part of the TTK Music Player project
# * Copyright (C) 2015 - 2021 Greedysky Studio
#
# * This program is free software; you can redistribute it and/or modify
# * it under the terms of the GNU General Public License as published by
# * the Free Software Foundation; either version 3 of the License, or
# * (at your option) any later version.
#
# * This program is distributed in the hope that it will be useful,
# * but WITHOUT ANY WARRANTY; without even the implied warranty of
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# * GNU General Public License for more details.
#
# * You should have received a copy of the GNU General Public License along
# * with this program; If not, see <http://www.gnu.org/licenses/>.
# =================================================

QT       += core

TEMPLATE = lib

include($$PWD/../../TTKVersion.pri)

DESTDIR = $$OUT_PWD/../../bin/$$TTKMusicPlayer
TARGET = TTKWatcher

CONFIG += warn_off plugin lib

unix{
    macx{
        SOURCES += $$PWD/qdevicewatcher_mac.cpp
        LIBS += -framework DiskArbitration -framework Foundation
    }else{
        SOURCES += $$PWD/qdevicewatcher_linux.cpp
    }
}

win32{
    wince*: SOURCES += $$PWD/qdevicewatcher_wince.cpp
    else: SOURCES += $$PWD/qdevicewatcher_win32.cpp
    LIBS *= -luser32
}

win32:msvc{
    CONFIG +=c++11
}else{
    QMAKE_CXXFLAGS += -std=c++11
}

SOURCES += \
    $$PWD/qdevicewatcher.cpp
    
HEADERS += \
    $$PWD/qdevicewatcher_p.h \
    $$PWD/qdevicewatcher.h

#load extra define
include($$PWD/../TTKExtrasDefine.pri)

win32{
    RC_FILE = TTKWatcher.rc
}
