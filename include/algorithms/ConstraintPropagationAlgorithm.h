#ifndef CONSTRAINTPROPAGATIONALGORITHM_H
#define CONSTRAINTPROPAGATIONALGORITHM_H

#include "SchedulingAlgorithmBase.h"

class ConstraintPropagationAlgorithm : public SchedulingAlgorithmBase
{
    Q_OBJECT

public:
    explicit ConstraintPropagationAlgorithm(QObject *parent = nullptr);
    void run() override;

private:
    bool backtrack(int step);
};

#endif // CONSTRAINTPROPAGATIONALGORITHM_H
