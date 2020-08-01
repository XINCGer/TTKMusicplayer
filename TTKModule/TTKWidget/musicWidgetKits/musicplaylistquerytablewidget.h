#ifndef MUSICPLAYLISTQUERYTABLEWIDGET_H
#define MUSICPLAYLISTQUERYTABLEWIDGET_H

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

#include "musicitemquerytablewidget.h"

/*! @brief The class of the playlist music query table widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_WIDGET_EXPORT MusicPlaylistQueryTableWidget : public MusicItemQueryTableWidget
{
    Q_OBJECT
    TTK_DECLARE_MODULE(MusicPlaylistQueryTableWidget)
public:
    /*!
     * Object contsructor.
     */
    explicit MusicPlaylistQueryTableWidget(QWidget *parent = nullptr);

    virtual ~MusicPlaylistQueryTableWidget();

    /*!
     * Set network query input.
     */
    virtual void setQueryInput(MusicAbstractQueryRequest *query) override;
    /*!
     * Set connect object.
     */
    void setConnectObject(QObject *obj);

};

#endif // MUSICPLAYLISTQUERYTABLEWIDGET_H
