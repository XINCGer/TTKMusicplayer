#ifndef MUSICNETWORKTESTTHREAD_H
#define MUSICNETWORKTESTTHREAD_H

#include <QThread>
#include "musicglobaldefine.h"

/*! @brief The class of thread to test input url network.
 * @author Greedysky <greedysky@163.com>
 */
class MUSIC_TOOLSET_EXPORT MusicNetworkTestThread : public QThread
{
    Q_OBJECT
public:
    /*!
     * Object contsructor.
     */
    explicit MusicNetworkTestThread(QObject *parent = 0);

    ~MusicNetworkTestThread();

    /*!
     * Get class object name.
     */
    static QString getClassName();
    /*!
     * Stop and quit current thread.
     */
    void stopAndQuitThread();
    /*!
     * Set current test url.
     */
    void setUrl(const QString &url);

Q_SIGNALS:
    /*!
     * Network connection test changed.
     */
    void networkConnectionTestChanged(bool state);

public Q_SLOTS:
    /*!
     * Strat thread now.
     */
    void start();
    /*!
     * Thread run now.
     */
    virtual void run() override;

protected:
    QString m_currentUrl;
    bool m_run;

};

#endif // MUSICNETWORKTESTTHREAD_H
