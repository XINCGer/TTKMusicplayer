#include "musicdesktopwallpaperthread.h"
#include "musicbackgroundconfigmanager.h"
#include "musicbackgroundmanager.h"
#include "musicextractwrap.h"

#include <QTimer>
#include <QPixmap>

MusicDesktopWallpaperThread::MusicDesktopWallpaperThread(QObject *parent)
    : QObject(parent)
{
    MusicTime::initRandom();

    m_run = false;
    m_random = false;
    m_currentImageIndex = 0;
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), SLOT(timeout()));

    setInterval(20 * MT_S2MS);
}

MusicDesktopWallpaperThread::~MusicDesktopWallpaperThread()
{
    stop();
    delete m_timer;
}

void MusicDesktopWallpaperThread::setInterval(int msec)
{
    m_timer->setInterval(msec);
}

bool MusicDesktopWallpaperThread::isRunning() const
{
    return m_run;
}

void MusicDesktopWallpaperThread::setRandom(bool random)
{
    m_random = random;
}
void MusicDesktopWallpaperThread::setImagePath(const QStringList &list)
{
    m_path = list;
}

#if defined Q_OS_WIN
HWND MusicDesktopWallpaperThread::findDesktopIconWnd()
{
    HWND hWorkerW = FindWindowExW(nullptr, nullptr, L"WorkerW", nullptr);
    HWND hDefView = nullptr;

    while(!hDefView && hWorkerW)
    {
        hDefView = FindWindowExW(hWorkerW, nullptr, L"SHELLDLL_DefView", nullptr);
        hWorkerW = FindWindowExW(nullptr, hWorkerW, L"WorkerW", nullptr);
    }

    ShowWindow(hWorkerW, 0);
    return FindWindowW(L"Progman", nullptr);
}

void MusicDesktopWallpaperThread::sendMessageToDesktop()
{
    PDWORD_PTR result = nullptr;
    SendMessageTimeoutW(FindWindowW(L"Progman", nullptr), 0x52C, 0, 0, SMTO_NORMAL, 1000, result);
}
#endif

void MusicDesktopWallpaperThread::start()
{
    m_run = true;
    timeout();
    m_timer->start();
}

void MusicDesktopWallpaperThread::stop()
{
    m_run = false;
    m_timer->stop();
}

void MusicDesktopWallpaperThread::timeout()
{
    if(!m_run)
    {
        return;
    }

    if(!m_path.isEmpty())
    {
        if(m_random) ///random mode
        {
            m_currentImageIndex = MusicTime::random(m_path.size());
        }
        else if(++m_currentImageIndex >= m_path.size())
        {
            m_currentImageIndex = 0;
        }

        Q_EMIT updateBackground(QPixmap(m_path[m_currentImageIndex]));
    }
    else
    {
        MusicBackgroundImage image;
        MusicExtractWrap::outputSkin(&image, G_BACKGROUND_PTR->getBackgroundUrl());

        Q_EMIT updateBackground(image.m_pix);
    }
}
