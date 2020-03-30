#ifndef MUSICDOWNLOADQUERYBDARTISTTHREAD_H
#define MUSICDOWNLOADQUERYBDARTISTTHREAD_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (C) 2015 - 2020 Greedysky Studio

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

#include "musicdownloadbdinterface.h"
#include "musicdownloadqueryartistthread.h"

/*! @brief The class to baidu query artist download data from net.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_NETWORK_EXPORT MusicDownLoadQueryBDArtistThread : public MusicDownLoadQueryArtistThread,
                                                              private MusicDownLoadBDInterface
{
    Q_OBJECT
    TTK_DECLARE_MODULE(MusicDownLoadQueryBDArtistThread)
public:
    /*!
     * Object contsructor.
     */
    explicit MusicDownLoadQueryBDArtistThread(QObject *parent = nullptr);

    /*!
     * Start to Search data from name and type.
     */
    virtual void startToSearch(const QString &artist) override;

public Q_SLOTS:
    /*!
     * Download data from net finished.
     */
    virtual void downLoadFinished() override;

protected:
    /*!
     * Get Download introduction data from net.
     */
    void getDownLoadIntro(MusicResultsItem *item);

};

#endif // MUSICDOWNLOADQUERYBDARTISTTHREAD_H
