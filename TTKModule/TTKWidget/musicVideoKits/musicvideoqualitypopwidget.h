#ifndef MUSICVIDEOQUALITYPOPWIDGET_H
#define MUSICVIDEOQUALITYPOPWIDGET_H

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

#include "musicobject.h"
#include "musictoolmenuwidget.h"

/*! @brief The class of the video quality popup widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_VIDEO_EXPORT MusicVideoQualityPopWidget : public MusicToolMenuWidget
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit MusicVideoQualityPopWidget(QWidget *parent = 0);

    virtual ~MusicVideoQualityPopWidget();

    /*!
     * Get class object name.
     */
    static QString getClassName();

    /*!
     * Set quality action state enable or disable.
     */
    void setQualityActionState();
    /*!
     * Set current media quality text.
     */
    void setQualityText(const QString &url);

Q_SIGNALS:
    /*!
     * Get music mv information data.
     */
    void getMusicMvInfo(MusicObject::MusicSongAttributes &data);
    /*!
     * Set current media url by selected quality.
     */
    void mvURLChanged(const QString &data);

public Q_SLOTS:
    /*!
     * Movie quality choiced by index.
     */
    void movieQualityChoiced(QAction *action);

protected:
    /*!
     * Create all widget in layout.
     */
    void initWidget();
    /*!
     * Find mv url by given bitrate.
     */
    QString findMVUrlByBitrate(int bitrate);
    /*!
     * Find mv bitrate by given url.
     */
    int findMVBitrateByUrl(const QString &url);
    /*!
     * Check given bitrate is exist or not.
     */
    bool findExistByBitrate(int bitrate);

    QActionGroup *m_actionGroup;

};

#endif // MUSICVIDEOQUALITYPOPWIDGET_H
