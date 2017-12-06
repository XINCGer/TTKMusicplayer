#include "musicdownloadquerythreadabstract.h"
#include "musicsemaphoreloop.h"

MusicDownLoadQueryThreadAbstract::MusicDownLoadQueryThreadAbstract(QObject *parent)
    : MusicDownLoadPagingThread(parent)
{
    m_queryAllRecords = false;
    m_querySimplify = false;
    m_queryExtraMovie = true;
    m_searchQuality = tr("SD");
    m_queryServer = "Invalid";
}

MusicDownLoadQueryThreadAbstract::~MusicDownLoadQueryThreadAbstract()
{
    deleteAll();
}

QString MusicDownLoadQueryThreadAbstract::getClassName()
{
    return staticMetaObject.className();
}

void MusicDownLoadQueryThreadAbstract::startToSingleSearch(const QString &text)
{
    Q_UNUSED(text);
}

QString MusicDownLoadQueryThreadAbstract::mapQueryServerString() const
{
    QString v = tr("Current Used Server Is %1");
    if(m_queryServer.contains("Baidu"))
        return v.arg(tr("BD"));
    else if(m_queryServer.contains("Kugou"))
        return v.arg(tr("KG"));
    else if(m_queryServer.contains("Kuwo"))
        return v.arg(tr("KW"));
    else if(m_queryServer.contains("QQ"))
        return v.arg(tr("QQ"));
    else if(m_queryServer.contains("WangYi"))
        return v.arg(tr("WY"));
    else if(m_queryServer.contains("XiaMi"))
        return v.arg(tr("XM"));
    else if(m_queryServer.contains("Migu"))
        return v.arg(tr("MG"));
    else if(m_queryServer.contains("WuSing"))
        return v.arg(tr("WS"));
    else if(m_queryServer.contains("YinYueTai"))
        return v.arg(tr("YYT"));
    else
        return QString();
}

qint64 MusicDownLoadQueryThreadAbstract::getUrlFileSize(const QString &url)
{
    qint64 size = -1;

    QNetworkAccessManager manager;
    QNetworkRequest request;
    request.setUrl(url);
#ifndef QT_NO_SSL
    QSslConfiguration sslConfig = request.sslConfiguration();
    sslConfig.setPeerVerifyMode(QSslSocket::VerifyNone);
    request.setSslConfiguration(sslConfig);
#endif
    MusicSemaphoreLoop loop;
    QNetworkReply *reply = manager.head(request);
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    connect(reply, SIGNAL(error(QNetworkReply::NetworkError)), &loop, SLOT(quit()));
    loop.exec();

    if(!reply || reply->error() != QNetworkReply::NoError)
    {
        return size;
    }

    size = reply->header(QNetworkRequest::ContentLengthHeader).toLongLong();
    QVariant redirection = reply->attribute(QNetworkRequest::RedirectionTargetAttribute);
    if(!redirection.isNull())
    {
        size = getUrlFileSize(redirection.toString());
    }

    reply->deleteLater();

    return size;
}
