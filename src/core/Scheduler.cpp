#include "Scheduler.h"
#include "BacktrackingAlgorithm.h"
#include "ConstraintPropagationAlgorithm.h"
#include "GeneticAlgorithm.h"
#include "SchedulingAlgorithmBase.h"

Scheduler::Scheduler(QObject *parent)
    : QObject(parent)
{}

Scheduler::~Scheduler()
{
    cleanUp();
}

void Scheduler::start(const QString &algorithm, const QVariantMap &config)
{
    // Bersihkan thread lama jika ada
    cleanUp();

    // Buat worker sesuai algoritma
    if (algorithm == "GENETIC") {
        m_worker = new GeneticAlgorithm;
    } else {
        emit scheduleFinished(false);
        return;
    }

    m_worker->init(config);

    m_thread = new QThread;
    m_worker->moveToThread(m_thread);

    // Hubungkan sinyal-sinyal utama
    connect(m_thread, &QThread::started, m_worker, &SchedulingAlgorithmBase::run);
    connect(m_worker, &SchedulingAlgorithmBase::progressChanged, this, &Scheduler::progressUpdated);
    connect(m_worker, &SchedulingAlgorithmBase::logMessage, this, &Scheduler::logEmitted);

    // Saat worker selesai, hentikan thread dan kirim status ke UI
    connect(m_worker, &SchedulingAlgorithmBase::finished, m_thread, &QThread::quit);
    connect(m_worker, &SchedulingAlgorithmBase::finished, this, [this]() {
        emit scheduleFinished(m_worker && !m_worker->isCancelled());
    });

    // Hapus worker dan thread setelah selesai (deleteLater)
    connect(m_thread, &QThread::finished, m_worker, &QObject::deleteLater);
    connect(m_thread, &QThread::finished, m_thread, &QObject::deleteLater);

    // Set pointer ke nullptr setelah benar-benar dihapus oleh Qt
    connect(m_worker, &QObject::destroyed, this, [this]() { m_worker = nullptr; });
    connect(m_thread, &QObject::destroyed, this, [this]() { m_thread = nullptr; });

    emit started();
    m_thread->start();
}

void Scheduler::cancel()
{
    // Minta worker membatalkan proses (thread-safe)
    if (m_worker)
        m_worker->requestCancel();
}

void Scheduler::handleFinished()
{
    // Tidak digunakan langsung, tapi tetap aman
    emit scheduleFinished(m_worker && !m_worker->isCancelled());
    if (m_thread)
        m_thread->quit();
}

SchedulingAlgorithmBase* Scheduler::createAlgorithm(const QString &name)
{
    if (name == "BACKTRACKING")
        return new BacktrackingAlgorithm;
    else if (name == "CONSTRAINT")
        return new ConstraintPropagationAlgorithm;
    else if (name == "GENETIC")
        return new GeneticAlgorithm;
    return nullptr;
}

void Scheduler::cleanUp()
{
    // Jika masih ada thread berjalan, minta cancel dan tunggu selesai
    if (m_thread && m_thread->isRunning()) {
        cancel();
        m_thread->quit();
        m_thread->wait();
        // Jangan hapus manual, deleteLater sudah diatur di start()
    }
    // Pointer akan di-set ke nullptr oleh slot destroyed
}
