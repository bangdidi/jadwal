#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H

#include "SchedulingAlgorithmBase.h"

// Algoritma penjadwalan berbasis genetic (atau simulasi backtracking)
class GeneticAlgorithm : public SchedulingAlgorithmBase
{
    Q_OBJECT

public:
    explicit GeneticAlgorithm(QObject *parent = nullptr);
    void run() override; // Implementasi utama algoritma

private:
    bool backtrack(int step); // Fungsi bantu (simulasi proses)
};

#endif // GENETICALGORITHM_H
