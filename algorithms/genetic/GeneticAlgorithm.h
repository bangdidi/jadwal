#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include <QObject>
#include <QVariantMap>

class GeneticAlgorithm : public QObject
{
    Q_OBJECT

public:
    explicit GeneticAlgorithm(QObject *parent = nullptr);

    void init(const QVariantMap &config);
    void run();
    void requestCancel();

signals:
    void progressChanged(int percent);
    void logMessage(const QString &message);
    void finished();

private:
    QVariantMap m_config;
    bool m_cancelled = false;
};

#endif // GENETICALGORITHM_H
