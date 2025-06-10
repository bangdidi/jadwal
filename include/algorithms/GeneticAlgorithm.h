#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include "SchedulingAlgorithmBase.h"

class GeneticAlgorithm : public SchedulingAlgorithmBase
{
    Q_OBJECT

public:
    explicit GeneticAlgorithm(QObject *parent = nullptr);
    void run() override;

private:
    bool backtrack(int step);
};

#endif // GENETICALGORITHM_H
