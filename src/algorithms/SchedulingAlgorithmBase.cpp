#include "SchedulingAlgorithmBase.h"

SchedulingAlgorithmBase::SchedulingAlgorithmBase(QObject *parent)
    : QObject(parent), m_cancelled(false)
{
}

SchedulingAlgorithmBase::~SchedulingAlgorithmBase()
{
}

void SchedulingAlgorithmBase::init(const QVariantMap &config)
{
    m_config = config;
    m_cancelled.store(false); // Reset status cancel setiap inisialisasi
}

void SchedulingAlgorithmBase::requestCancel()
{
    m_cancelled.store(true); // Tandai proses agar dibatalkan (thread-safe)
}

bool SchedulingAlgorithmBase::isCancelled() const
{
    return m_cancelled.load();
}
