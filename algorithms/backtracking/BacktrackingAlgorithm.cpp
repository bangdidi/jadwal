#include "BacktrackingAlgorithm.h"
#include <QDebug>

void BacktrackingAlgorithm::init(const QVariantMap &config)
{
    timeout = config.value("timeout", 60).toInt();
    forwardChecking = config.value("forwardChecking", true).toBool();
    variableOrdering = config.value("variableOrdering", "Most constrained").toString();
    valueOrdering = config.value("valueOrdering", "Least constraining").toString();
    enablePruning = config.value("enablePruning", true).toBool();
    maxBacktracks = config.value("maxBacktracks", 1000).toInt();
}

void BacktrackingAlgorithm::run()
{
    qDebug() << "Running Backtracking Algorithm with config:";
    qDebug() << "timeout:" << timeout
             << ", forwardChecking:" << forwardChecking
             << ", variableOrdering:" << variableOrdering
             << ", valueOrdering:" << valueOrdering
             << ", enablePruning:" << enablePruning
             << ", maxBacktracks:" << maxBacktracks;
}
