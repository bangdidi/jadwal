#include "ProcessPage.h"
#include "ui_ProcessPage.h"

ProcessPage::ProcessPage(QWidget *parent)
    : QWidget(parent), ui(new Ui::ProcessPage)
{
    ui->setupUi(this);

    connect(ui->cancelButton, &QPushButton::clicked,
            this, &ProcessPage::cancelRequested);
}

ProcessPage::~ProcessPage()
{
    delete ui;
}

void ProcessPage::updateProgress(int percent)
{
    ui->progressBar->setValue(percent);
}

void ProcessPage::logMessage(const QString &message)
{
    ui->logTextEdit->append(message);
}

void ProcessPage::onFinished()
{
    ui->statusLabel->setText("Finished");
    ui->cancelButton->setEnabled(false);
}
