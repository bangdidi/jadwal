#include "GeneticAlgorithm.h"

#include <QThread>
#include <QDebug>

GeneticAlgorithm::GeneticAlgorithm(QObject *parent)
    : QObject(parent)
{}

void GeneticAlgorithm::init(const QVariantMap &config)
{
    m_config = config;
}

void GeneticAlgorithm::requestCancel()
{
    m_cancelled = true;
}

void GeneticAlgorithm::run()
{
    emit logMessage("Starting Genetic Algorithm...");
    for (int i = 0; i <= 100; i += 10) {
        if (m_cancelled) {
            emit logMessage("Process cancelled.");
            emit finished();
            return;
        }

        QThread::sleep(1);
        emit progressChanged(i);
        emit logMessage(QString("Progress: %1%").arg(i));
    }

    emit logMessage("Genetic Algorithm completed.");
    emit finished();
}
