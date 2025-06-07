#include "ConstraintAlgorithm.h"
#include <QDebug>

void ConstraintAlgorithm::init(const QVariantMap &config)
{
    timeout = config.value("timeout", 60).toInt();
    variableOrdering = config.value("variableOrdering", "Smallest Domain").toString();
    valueOrdering = config.value("valueOrdering", "Least Constraining").toString();
    propagation = config.value("propagation", "AC-3").toString();
    maxBacktracks = config.value("maxBacktracks", 1000).toInt();
}

void ConstraintAlgorithm::run()
{
    qDebug() << "Running Constraint Propagation Algorithm with config:";
    qDebug() << "timeout:" << timeout
             << ", variableOrdering:" << variableOrdering
             << ", valueOrdering:" << valueOrdering
             << ", propagation:" << propagation
             << ", maxBacktracks:" << maxBacktracks;
}
