#include "musicbdcommentsrequest.h"
#include "musicbdqueryrequest.h"
#include "musicsemaphoreloop.h"
#include "musicurlutils.h"

#include "qalg/qaeswrap.h"

MusicBDSongCommentsRequest::MusicBDSongCommentsRequest(QObject *parent)
    : MusicCommentsRequest(parent)
{
    m_pageSize = 20;
}

void MusicBDSongCommentsRequest::startToSearch(const QString &name)
{
    TTK_LOGGER_INFO(QString("%1 startToSearch %2").arg(getClassName()).arg(name));

    MusicSemaphoreLoop loop;
    MusicBDQueryRequest *d = new MusicBDQueryRequest(this);
    d->setQueryAllRecords(false);
    d->setQuerySimplify(true);
    d->startToSearch(MusicAbstractQueryRequest::MusicQuery, name);
    connect(d, SIGNAL(downLoadDataChanged(QString)), &loop, SLOT(quit()));
    loop.exec();

    m_rawData["songID"] = 0;
    if(!d->isEmpty())
    {
        m_rawData["songID"] = d->getMusicSongInfos().first().m_songId.toInt();
        startToPage(0);
    }
}

void MusicBDSongCommentsRequest::startToPage(int offset)
{
    if(!m_manager)
    {
        return;
    }

    TTK_LOGGER_INFO(QString("%1 startToPage %2").arg(getClassName()).arg(offset));
    deleteAll();

    const QString &time = "1494911685";
    const QString &key = MusicUtils::Algorithm::md5(QString("baidu_taihe_music_secret_key" + time).toUtf8()).toHex().mid(8, 16);
    const QString &data = MusicUtils::Algorithm::mdII(BD_COMMENT_SONG_URL, false).arg(m_pageSize*offset).arg(m_pageSize).arg(m_rawData["songID"].toInt());
    QString eKey = QAesWrap().encryptCBC(data.toUtf8(), key.toUtf8(), key.toUtf8());
    const QString &sign = MusicUtils::Algorithm::md5(QString("baidu_taihe_music" + eKey + time).toUtf8()).toHex();
    MusicUtils::Url::urlEncode(eKey);
    const QUrl &musicUrl = MusicUtils::Algorithm::mdII(BD_COMMENT_URL, false).arg(time).arg(sign).arg(eKey);

    m_pageTotal = 0;
    m_interrupt = true;

    QNetworkRequest request;
    request.setUrl(musicUrl);
    request.setRawHeader("User-Agent", MusicUtils::Algorithm::mdII(BD_UA_URL, ALG_UA_KEY, false).toUtf8());
    MusicObject::setSslConfiguration(&request);

    m_reply = m_manager->get(request);
    connect(m_reply, SIGNAL(finished()), SLOT(downLoadFinished()));
    connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), SLOT(replyError(QNetworkReply::NetworkError)));
}

void MusicBDSongCommentsRequest::downLoadFinished()
{
    if(!m_reply)
    {
        deleteAll();
        return;
    }

    TTK_LOGGER_INFO(QString("%1 downLoadFinished").arg(getClassName()));
    m_interrupt = false;

    if(m_reply->error() == QNetworkReply::NoError)
    {
        const QByteArray &bytes = m_reply->readAll();

        QJson::Parser parser;
        bool ok;
        const QVariant &data = parser.parse(bytes, &ok);
        if(ok)
        {
            QVariantMap value = data.toMap();
            if(value["error_code"].toInt() == 22000 && value.contains("result"))
            {
                value = value["result"].toMap();
                m_pageTotal = value["commentlist_last_nums"].toLongLong();

                const QVariantList &comments = value["commentlist_last"].toList();
                for(const QVariant &comm : qAsConst(comments))
                {
                    if(comm.isNull())
                    {
                        continue;
                    }

                    if(m_interrupt) return;

                    MusicResultsItem comment;
                    value = comm.toMap();
                    comment.m_playCount = QString::number(value["zan_num"].toLongLong());
                    comment.m_updateTime = QString::number(value["ctime"].toLongLong() * 1000);
                    comment.m_description = value["comment"].toString();

                    const QVariantMap &user = value["author"].toMap();
                    comment.m_nickName = user["username"].toString();
                    comment.m_coverUrl = user["userpic"].toString();

                    Q_EMIT createSearchedItem(comment);
                }
            }
        }
    }

    Q_EMIT downLoadDataChanged(QString());
    deleteAll();
}



MusicBDPlaylistCommentsRequest::MusicBDPlaylistCommentsRequest(QObject *parent)
    : MusicCommentsRequest(parent)
{
    m_pageSize = 20;
}

void MusicBDPlaylistCommentsRequest::startToSearch(const QString &name)
{
    TTK_LOGGER_INFO(QString("%1 startToSearch %2").arg(getClassName()).arg(name));

    m_rawData["songID"] = name;
    startToPage(0);
}

void MusicBDPlaylistCommentsRequest::startToPage(int offset)
{
    if(!m_manager)
    {
        return;
    }

    TTK_LOGGER_INFO(QString("%1 startToPage %2").arg(getClassName()).arg(offset));
    deleteAll();

    const QString &time = "1494911685";
    const QString &key = MusicUtils::Algorithm::md5(QString("baidu_taihe_music_secret_key" + time).toUtf8()).toHex().mid(8, 16);
    const QString &data = MusicUtils::Algorithm::mdII(BD_COMMENT_PLAYLIST_URL, false).arg(m_pageSize*offset).arg(m_pageSize).arg(m_rawData["songID"].toInt());
    QString eKey = QAesWrap().encryptCBC(data.toUtf8(), key.toUtf8(), key.toUtf8());
    const QString &sign = MusicUtils::Algorithm::md5(QString("baidu_taihe_music" + eKey + time).toUtf8()).toHex();
    eKey.replace("+", "%2B");
    eKey.replace("/", "%2F");
    eKey.replace("=", "%3D");
    const QUrl &musicUrl = MusicUtils::Algorithm::mdII(BD_COMMENT_URL, false).arg(time).arg(sign).arg(eKey);

    m_pageTotal = 0;
    m_interrupt = true;

    QNetworkRequest request;
    request.setUrl(musicUrl);
    request.setRawHeader("User-Agent", MusicUtils::Algorithm::mdII(BD_UA_URL, ALG_UA_KEY, false).toUtf8());
    MusicObject::setSslConfiguration(&request);

    m_reply = m_manager->get(request);
    connect(m_reply, SIGNAL(finished()), SLOT(downLoadFinished()));
    connect(m_reply, SIGNAL(error(QNetworkReply::NetworkError)), SLOT(replyError(QNetworkReply::NetworkError)));
}

void MusicBDPlaylistCommentsRequest::downLoadFinished()
{
    if(!m_reply)
    {
        deleteAll();
        return;
    }

    TTK_LOGGER_INFO(QString("%1 downLoadFinished").arg(getClassName()));
    m_interrupt = false;

    if(m_reply->error() == QNetworkReply::NoError)
    {
        const QByteArray &bytes = m_reply->readAll();

        QJson::Parser parser;
        bool ok;
        const QVariant &data = parser.parse(bytes, &ok);
        if(ok)
        {
            QVariantMap value = data.toMap();
            if(value["error_code"].toInt() == 22000 && value.contains("result"))
            {
                value = value["result"].toMap();
                m_pageTotal = value["commentlist_last_nums"].toLongLong();

                const QVariantList &comments = value["commentlist_last"].toList();
                for(const QVariant &comm : qAsConst(comments))
                {
                    if(comm.isNull())
                    {
                        continue;
                    }

                    if(m_interrupt) return;

                    MusicResultsItem comment;
                    value = comm.toMap();
                    comment.m_playCount= QString::number(value["zan_num"].toLongLong());
                    comment.m_updateTime = QString::number(value["ctime"].toLongLong() * 1000);
                    comment.m_description = value["comment"].toString();

                    const QVariantMap &user = value["author"].toMap();
                    comment.m_nickName = user["username"].toString();
                    comment.m_coverUrl= user["userpic"].toString();

                    Q_EMIT createSearchedItem(comment);
                }
            }
        }
    }

    Q_EMIT downLoadDataChanged(QString());
    deleteAll();
}
