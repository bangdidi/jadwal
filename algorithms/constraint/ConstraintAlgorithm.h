#ifndef CONSTRAINTALGORITHM_H
#define CONSTRAINTALGORITHM_H

#include <QVariantMap>
#include <QString>

class ConstraintAlgorithm
{
public:
    void init(const QVariantMap &config);
    void run();

private:
    int timeout;
    QString variableOrdering;
    QString valueOrdering;
    QString propagation;
    int maxBacktracks;
};

#endif // CONSTRAINTALGORITHM_H
