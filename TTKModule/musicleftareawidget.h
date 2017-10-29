#ifndef MUSICLEFTAREAWIDGET_H
#define MUSICLEFTAREAWIDGET_H

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

#include <QWidget>
#include "musicglobaldefine.h"

class MusicSoundKMicroWidget;
class MusicCloudSharedSongWidget;
class MusicQualityChoicePopWidget;

namespace Ui {
    class MusicApplication;
}

/*! @brief The class of the app left area widget.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_GUI_EXPORT MusicLeftAreaWidget : public QWidget
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit MusicLeftAreaWidget(QWidget *parent = 0);

    ~MusicLeftAreaWidget();
    /*!
     * Get class object name.
     */
    static QString getClassName();
    /*!
     * Get class object instance.
     */
    static MusicLeftAreaWidget *instance();
    /*!
     * Set up app ui.
     */
    void setupUi(Ui::MusicApplication* ui);
    /*!
     * Reset current music love icon state.
     */
    void musictLoveStateClicked(bool state);
    /*!
     * Create sound KMicro widget.
     */
    void createSoundKMicroWidget(const QString &name);
    /*!
     * Current is show full container.
     */
    bool isLrcWidgetShowFullScreen() const;

Q_SIGNALS:
    /*!
     * Current music love icon state changed.
     */
    void currentLoveStateChanged();
    /*!
     * Current music download icon state changed.
     */
    void currentDownloadStateChanged();

public Q_SLOTS:
    /*!
     * Set list background skin transparent.
     */
    void setTransparent(int index);
    /*!
     * To download music data from net to load.
     */
    void musicDownloadSongToLocal();
    /*!
     * To download music data from net finished.
     */
    void musicDownloadSongFinished();
    /*!
     * All files upload finsihed.
     */
    void cloudSharedSongUploadAllDone();
    /*!
     * Show full container or not.
     */
    void lrcWidgetShowFullScreen();
    /*!
     * Switch to selected item style.
     */
    void switchToSelectedItemStyle(int index);
    /*!
     * Change to song list widget.
     */
    void musicStackedSongListWidgetChanged();
    /*!
     * Change to radio widget.
     */
    void musicStackedRadioWidgetChanged();
    /*!
     * Change to my download widget.
     */
    void musicStackedMyDownWidgetChanged();
    /*!
     * Change to mobile widget.
     */
    void musicStackedMobileWidgetChanged();
    /*!
     * Change to shared cloud widget.
     */
    void musicStackedCloudWidgetChanged();

protected:
    Ui::MusicApplication *m_ui;

    int m_currentIndex;
    bool m_lrcWidgetShowFullScreen;
    QWidget *m_stackedWidget;
    MusicSoundKMicroWidget *m_soundKMicroWidget;
    MusicQualityChoicePopWidget *m_qualityChoiceWidget;
    MusicCloudSharedSongWidget *m_cloudSharedSongWidget;

    static MusicLeftAreaWidget *m_instance;
};

#endif // MUSICLEFTAREAWIDGET_H
