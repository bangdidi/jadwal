#ifndef SCHEDULINGALGORITHMBASE_H
#define SCHEDULINGALGORITHMBASE_H

#include <QObject>
#include <QVariantMap>
#include <atomic>

class SchedulingAlgorithmBase : public QObject
{
    Q_OBJECT

public:
    explicit SchedulingAlgorithmBase(QObject *parent = nullptr);
    virtual ~SchedulingAlgorithmBase();

    void init(const QVariantMap &config);
    virtual void run() = 0;

    void requestCancel();
    bool isCancelled() const;

signals:
    void progressChanged(int percent);
    void logMessage(const QString &message);
    void finished();

protected:
    QVariantMap m_config;
    std::atomic_bool m_cancelled {false};
};

#endif // SCHEDULINGALGORITHMBASE_H
