#ifndef BACKTRACKINGALGORITHM_H
#define BACKTRACKINGALGORITHM_H

#include "SchedulingAlgorithmBase.h"

class BacktrackingAlgorithm : public SchedulingAlgorithmBase
{
    Q_OBJECT

public:
    explicit BacktrackingAlgorithm(QObject *parent = nullptr);
    void run() override;

private:
    bool backtrack(int step);
};

#endif // BACKTRACKINGALGORITHM_H
