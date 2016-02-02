/***************************************************************************
 *   Copyright (C) 2009-2013 by Ilya Kotov                                 *
 *   forkotov02@hotmail.ru                                                 *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.         *
 ***************************************************************************/


#include "outputwaveout.h"
#include "outputwaveoutfactory.h"
#include <QMessageBox>
#include <QTranslator>

const OutputProperties OutputWaveOutFactory::properties() const
{
    OutputProperties properties;
    properties.name = tr("WaveOut Plugin");
    properties.hasAbout = true;
    properties.hasSettings = false;
    properties.shortName = "waveout";
    return properties;
}

Output* OutputWaveOutFactory::create()
{
    return new OutputWaveOut();
}

Volume *OutputWaveOutFactory::createVolume()
{
    VolumeWaveOut *vol = new VolumeWaveOut();
    if(!vol->isSupported())
    {
        qDebug("OutputWaveOutFactory: device doesn't support volume control");
        delete vol;
        return 0;
    }
    return vol;
}
