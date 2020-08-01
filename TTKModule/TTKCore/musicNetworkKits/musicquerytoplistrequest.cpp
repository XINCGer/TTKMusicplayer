#include "musicquerytoplistrequest.h"

MusicQueryToplistRequest::MusicQueryToplistRequest(QObject *parent)
    : MusicAbstractQueryRequest(parent)
{

}

void MusicQueryToplistRequest::startToSearch(QueryType type, const QString &artist)
{
    Q_UNUSED(type);
    startToSearch(artist);
}
