#ifndef MUSICEXTRACTWRAP_H
#define MUSICEXTRACTWRAP_H

/* =================================================
 * This file is part of the TTK Music Player project
 * Copyright (C) 2015 - 2021 Greedysky Studio

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

#include "musicglobaldefine.h"

class MusicBackgroundImage;

/*! @brief The class of the extract data wrap.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_CORE_EXPORT MusicExtractWrap
{
    TTK_DECLARE_MODULE(MusicExtractWrap)
public:
    /*!
     * Transfer file to image data.
     */
    static bool outputThunderSkin(QPixmap &image, const QString &input);

    /*!
     * Transfer file to normal data.
     */
    static bool outputBinary(const QString &input);
    /*!
     * Transfer file to normal data.
     */
    static bool outputBinary(const QString &input, const QString &output);
    /*!
     * Transfer file to normal data.
     */
    static bool outputBinary(const QString &input, const QString &output, QStringList &path);

    /*!
     * Transfer file to image data.
     */
    static bool outputSkin(MusicBackgroundImage *image, const QString &input);
    /*!
     * Transfer image data to file.
     */
    static bool inputSkin(MusicBackgroundImage *image, const QString &output);

    /*!
     * Transfer file to data.
     */
    static bool outputData(QByteArray &data, const QString &input);
    /*!
     * Transfer data to file.
     */
    static bool inputData(const QByteArray &data, const QString &output);

};

#endif // MUSICEXTRACTWRAP_H
