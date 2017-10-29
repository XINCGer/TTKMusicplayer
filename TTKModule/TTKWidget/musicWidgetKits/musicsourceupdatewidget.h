#ifndef MUSICSOURCEUPDATEWIDGET_H
#define MUSICSOURCEUPDATEWIDGET_H

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

#include "musicabstractmovedialog.h"
#include "musicabstractmovewidget.h"

#define CSDN_URL        "S1Nqc1N0ZmI3c3pHeWE2Z1BhMTE4WlFVMjNBVG5qRjZkZ0tVRmV2L0VJeVF0bUlTOGE1Zmp3Z0xpZWRpM25lOA=="

namespace Ui {
class MusicSourceUpdateWidget;
}


/*! @brief The class of the application upgrade notify widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_WIDGET_EXPORT MusicSourceUpdateNotifyWidget : public MusicAbstractMoveSingleWidget
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit MusicSourceUpdateNotifyWidget(QWidget *parent = 0);

    ~MusicSourceUpdateNotifyWidget();

    /*!
     * Get class object name.
     */
    static QString getClassName();

    /*!
     * Start update.
     */
    void start();

public Q_SLOTS:
    /*!
     * Update source clicked.
     */
    void updateSourceClicked();
    /*!
     * Download data from kuwo net finished.
     */
    void downLoadFinished(const QVariant &data);

protected:
    QLabel *m_textLabel;

};


/*! @brief The class of the application upgrade widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_WIDGET_EXPORT MusicSourceUpdateWidget : public MusicAbstractMoveDialog
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit MusicSourceUpdateWidget(QWidget *parent = 0);

    virtual ~MusicSourceUpdateWidget();

    /*!
     * Get class object name.
     */
    static QString getClassName();

    /*!
     * Start update.
     */
    void start();

public Q_SLOTS:
    /*!
     * Upgrade button clicked.
     */
    void upgradeButtonClicked();
    /*!
     * Upgrade failed clicked.
     */
    void upgradeFailedClicked();
    /*!
     * Download data from kuwo net finished.
     */
    void downLoadFinished(const QVariant &data);
    /*!
     * Update download speed label.
     */
    void downloadSpeedLabelChanged(const QString &speed, qint64 timeLeft);
    /*!
     * Update download percent\ total size progress.
     */
    void downloadProgressChanged(float percent, const QString &total);
    /*!
     * Update download progress finished.
     */
    void downloadProgressFinished();
    /*!
     * Override exec function.
     */
    virtual int exec();

protected:
    Ui::MusicSourceUpdateWidget *m_ui;
    QString m_newVersionStr;

};

#endif // MUSICSOURCEUPDATEWIDGET_H
