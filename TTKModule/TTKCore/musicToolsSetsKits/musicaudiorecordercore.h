#ifndef MUSICAUDIORECORDERCORE_H
#define MUSICAUDIORECORDERCORE_H

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

#include <QFile>
#include <QAudioInput>
#include <QAudioOutput>
#include <QAudioDeviceInfo>
#include "musicglobaldefine.h"
#include "musicotherdefine.h"

/*! @brief The class of the audio recorder core.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_TOOLSET_EXPORT MusicAudioRecorderCore : public QObject
{
    Q_OBJECT
public:
    /*! @brief The class of the audio file tag header.
     * @author Greedysky <greedysky@163.com>
     */
    typedef struct MUSIC_TOOLSET_EXPORT HEADER
    {
        char RIFFNAME[4];
        unsigned long nRIFFLength;
        char WAVNAME[4];
        char FMTNAME[4];
        unsigned long nFMTLength;
        unsigned short nAudioFormat;
        unsigned short nChannleNumber;
        unsigned long nSampleRate;
        unsigned long nBytesPerSecond;
        unsigned short nBytesPerSample;
        unsigned short    nBitsPerSample;
        char    DATANAME[4];
        unsigned long   nDataLength;
    }HEADER;

    /*!
     * Object contsructor.
     */
    explicit MusicAudioRecorderCore(QObject *parent = 0);

    ~MusicAudioRecorderCore();

    /*!
     * Get class object name.
     */
    static QString getClassName();

    /*!
     * Add the header of wav.
     */
    int addWavHeader(const char *filename);

    /*!
     * Set volume by value.
     */
    void setVolume(int volume);
    /*!
     * Get volume by value.
     */
    int volume() const;

    /*!
     * Set output file name.
     */
    void setFileName(const QString &name);
    /*!
     * Get output file name.
     */
    QString getFileName() const;
    /*!
     * Current input device error or not.
     */
    bool error() const;

public Q_SLOTS:
    /*!
     * Recorder play start.
     */
    void onRecordStart();
    /*!
     * Recorder play stop.
     */
    void onRecordStop();
    /*!
     * Recorder play play.
     */
    void onRecordPlay();
    /*!
     * Recorder play state changed.
     */
    void onStateChange(QAudio::State state);

protected:
    int m_inputVolume;
    QAudioFormat m_mFormatFile;
    QFile *m_mpOutputFile;
    QAudioInput *m_mpAudioInputFile;
    QAudioOutput *m_mpAudioOutputFile;

};

#endif // MUSICAUDIORECORDERCORE_H
