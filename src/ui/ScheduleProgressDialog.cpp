#include "ScheduleProgressDialog.h"
#include "ui_ScheduleProgressDialog.h"

#include <QCloseEvent>

ScheduleProgressDialog::ScheduleProgressDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ScheduleProgressDialog)
{
    ui->setupUi(this);
}

ScheduleProgressDialog::~ScheduleProgressDialog()
{
    delete ui;
}

void ScheduleProgressDialog::updateProgress(int percent)
{
    ui->progressBar->setValue(percent);
}

void ScheduleProgressDialog::appendLogMessage(const QString &message)
{
    ui->textEditLog->append(message);
}

void ScheduleProgressDialog::on_buttonCancel_clicked()
{
    emit cancelRequested();
}

void ScheduleProgressDialog::onFinished(bool success)
{
    // Pastikan hanya dipanggil sekali
    if (m_finished) return;
    m_finished = true;

    // Disconnect cancel agar tidak ada sinyal cancel setelah selesai
    disconnect(this, &ScheduleProgressDialog::cancelRequested, nullptr, nullptr);

    if (isVisible()) {
        emit dialogFinished(success);
        accept(); // Tutup dialog dengan status Accepted
    }
}

void ScheduleProgressDialog::closeEvent(QCloseEvent *event)
{
    // Jika proses belum selesai, trigger cancel dan cegah penutupan
    if (!m_finished) {
        emit cancelRequested();
        event->ignore();
    } else {
        QDialog::closeEvent(event);
    }
}
