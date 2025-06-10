#include "BacktrackingAlgorithm.h"

#include <QThread>

BacktrackingAlgorithm::BacktrackingAlgorithm(QObject *parent)
    : SchedulingAlgorithmBase(parent)
{
}

void BacktrackingAlgorithm::run()
{
    emit logMessage(tr("Schedule generation started."));

    bool success = backtrack(0);

    if (isCancelled()) {
        emit logMessage(tr("Schedule generation cancelled by user."));
    } else if (success) {
        emit logMessage(tr("Schedule generation completed successfully."));
    } else {
        emit logMessage(tr("Schedule generation failed to find a solution."));
    }

    emit finished();
}

bool BacktrackingAlgorithm::backtrack(int step)
{
    if (isCancelled()) return false;

    if (step >= 100) {
        return true;
    }

    emit progressChanged(step);
    emit logMessage(QString("Trying step %1...").arg(step));
    QThread::msleep(30);

    if (backtrack(step + 1)) {
        return true;
    }

    return false;
}
