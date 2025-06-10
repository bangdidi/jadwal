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
    if (m_finished) return;
    m_finished = true;

    disconnect(this, &ScheduleProgressDialog::cancelRequested, nullptr, nullptr); // opsional ekstra aman

    if (isVisible()) {
        emit dialogFinished(success);
        accept();
    }
}

void ScheduleProgressDialog::closeEvent(QCloseEvent *event)
{
    if (!m_finished) {
        emit cancelRequested();
        event->ignore();
    } else {
        event->accept();
    }
}
