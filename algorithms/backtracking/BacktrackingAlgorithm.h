#ifndef BACKTRACKINGALGORITHM_H
#define BACKTRACKINGALGORITHM_H

#include <QVariantMap>
#include <QString>

class BacktrackingAlgorithm
{
public:
    void init(const QVariantMap &config);
    void run();

private:
    int timeout;
    bool forwardChecking;
    QString variableOrdering;
    QString valueOrdering;
    bool enablePruning;
    int maxBacktracks;
};

#endif // BACKTRACKINGALGORITHM_H
