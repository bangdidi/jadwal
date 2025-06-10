#ifndef SCHEDULER_H
#define SCHEDULER_H

#include <QObject>
#include <QVariantMap>
#include <QThread>

class SchedulingAlgorithmBase;

class Scheduler : public QObject
{
    Q_OBJECT

public:
    explicit Scheduler(QObject *parent = nullptr);
    ~Scheduler();

    void start(const QString &algorithmName, const QVariantMap &config);
    void cancel();

signals:
    void started();
    void progressUpdated(int value);
    void logEmitted(const QString &message);
    void scheduleFinished(bool success);

private slots:
    void handleFinished();

private:
    SchedulingAlgorithmBase *m_worker = nullptr;
    QThread *m_thread = nullptr;

    SchedulingAlgorithmBase* createAlgorithm(const QString &name);
    void cleanUp();
};

#endif // SCHEDULER_H
