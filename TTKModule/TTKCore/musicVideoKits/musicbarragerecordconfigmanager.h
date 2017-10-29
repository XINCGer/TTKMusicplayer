#ifndef MUSICBARRAGERECORDCONFIGMANAGER_H
#define MUSICBARRAGERECORDCONFIGMANAGER_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (C) 2015 - 2017 Greedysky Studio

 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.

 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.

 * You should have received a copy of the GNU General Public License along
 * with this program; If not, see <http://www.gnu.org/licenses/>.
 ================================================= */

#include "musicabstractxml.h"

/*! @brief The class of the barrage record item.
 * @author Greedysky <greedysky@163.com>
 */
typedef struct MUSIC_VIDEO_EXPORT MusicBarrageRecord
{
    int m_size;
    QString m_color;
    QString m_value;
}MusicBarrageRecord;
MUSIC_DECLARE_LISTS(MusicBarrageRecord)

/*! @brief The class of the barrage record manager.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_VIDEO_EXPORT MusicBarrageRecordConfigManager : public MusicAbstractXml
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit MusicBarrageRecordConfigManager(QObject *parent = 0);

    /*!
     * Get class object name.
     */
    static QString getClassName();
    /*!
     * Read barrage datas from xml file by given name.
     */
    inline bool readBarrageXMLConfig(){ return readConfig(BARRAGEPATH_FULL); }
    /*!
     * Write barrage datas into xml file.
     */
    void writeBarrageConfig(const MusicBarrageRecords &records);
    /*!
     * Read barrage datas into xml file.
     */
    void readBarrageConfig(MusicBarrageRecords &records);

};

#endif // MUSICBARRAGERECORDCONFIGMANAGER_H
