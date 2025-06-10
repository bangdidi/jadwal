#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "core/ApplicationManager.h"
#include "core/Scheduler.h"
#include "SettingDialog.h"
#include "ScheduleSetupDialog.h"
#include "ScheduleProgressDialog.h"
#include "AboutDialog.h"

#include <QScreen>
#include <QGuiApplication>
#include <QMessageBox>
#include <QProcess>
#include <QCoreApplication>

MainWindow::MainWindow(ApplicationManager *appManager, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      m_appManager(appManager),
      m_scheduler(new Scheduler(this))
{
    ui->setupUi(this);

    // Center window
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();
    move(screenGeometry.center() - rect().center());

    // Connect scheduler signal
    connect(m_scheduler, &Scheduler::scheduleFinished, this, &MainWindow::onScheduleFinished);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionSetting_triggered()
{
    SettingDialog dialog(this);
    dialog.loadSettings(m_appManager->settings());

    QString oldLang = m_appManager->language();
    if (dialog.exec() == QDialog::Accepted) {
        dialog.saveSettings(m_appManager->settings());
        QString newLang = m_appManager->settings()->value("application/language", oldLang).toString();

        if (newLang != oldLang) {
            auto reply = QMessageBox::question(
                this, tr("Restart Required"),
                tr("The application needs to restart to apply the language change. Restart now?"),
                QMessageBox::Yes | QMessageBox::No
            );
            if (reply == QMessageBox::Yes) {
                restartApplication();
            }
        }
    }
}

void MainWindow::on_actionGenerate_triggered()
{
    ScheduleSetupDialog dialog(this);
    connect(&dialog, &ScheduleSetupDialog::configurationReady,
            this, &MainWindow::onConfigurationReady);
    dialog.exec();
}

void MainWindow::onConfigurationReady(const QString &algorithm, const QVariantMap &config)
{
    if (m_progressDialog) {
        m_progressDialog->deleteLater();
        m_progressDialog = nullptr;
    }

    m_progressDialog = new ScheduleProgressDialog(this);

    // Hubungkan progress dan log
    connect(m_scheduler, &Scheduler::progressUpdated,
            m_progressDialog, &ScheduleProgressDialog::updateProgress);
    connect(m_scheduler, &Scheduler::logEmitted,
            m_progressDialog, &ScheduleProgressDialog::appendLogMessage);

    // Hubungkan tombol Cancel
    connect(m_progressDialog, &ScheduleProgressDialog::cancelRequested,
            m_scheduler, &Scheduler::cancel, Qt::DirectConnection);

    // Tampilkan dialog saat proses mulai
    connect(m_scheduler, &Scheduler::started, this, [this]() {
        m_progressDialog->show();
    });

    // Tunggu hasil dari Scheduler
    connect(m_scheduler, &Scheduler::scheduleFinished, m_progressDialog, &ScheduleProgressDialog::onFinished);

    // Dialog selesai, tampilkan notifikasi dan bersihkan
    connect(m_progressDialog, &ScheduleProgressDialog::dialogFinished,
            this, [this](bool success) {
        if (success) {
            QMessageBox::information(this, tr("Success"), tr("Schedule successfully generated."));
            ui->tabWidget->setCurrentWidget(ui->tabSchedule);
        } else {
            QMessageBox::warning(this, tr("Cancelled"), tr("Schedule generation cancelled or failed."));
        }

        m_progressDialog->deleteLater();
        m_progressDialog = nullptr;
    });

    m_scheduler->start(algorithm, config);
}

void MainWindow::onScheduleFinished(bool success)
{
    /*
    if (success) {
        QMessageBox::information(this, tr("Success"), tr("Schedule successfully generated."));
        ui->tabWidget->setCurrentWidget(ui->tabSchedule);
    } else {
        QMessageBox::warning(this, tr("Cancelled"), tr("Schedule generation cancelled or failed."));
    }
    */
}

void MainWindow::on_actionAbout_triggered()
{
    AboutDialog dialog(this);
    dialog.exec();
}

void MainWindow::on_actionExit_triggered() { close(); }
void MainWindow::on_actionNewProject_triggered() { QMessageBox::information(this, "New", "New Project"); }
void MainWindow::on_actionOpenProject_triggered() { QMessageBox::information(this, "Open", "Open Project"); }
void MainWindow::on_actionSaveProject_triggered() { QMessageBox::information(this, "Save", "Save Project"); }
void MainWindow::on_actionSaveProjectAs_triggered() { QMessageBox::information(this, "Save As", "Save Project As"); }

void MainWindow::on_actionImport_triggered() { QMessageBox::information(this, "Import", "Import Data"); }
void MainWindow::on_actionSubject_triggered() { QMessageBox::information(this, "Subject", "Subject Entry"); }
void MainWindow::on_actionTeacher_triggered() { QMessageBox::information(this, "Teacher", "Teacher Entry"); }
void MainWindow::on_actionClassroom_triggered() { QMessageBox::information(this, "Classroom", "Classroom Entry"); }
void MainWindow::on_actionClassroomSubject_triggered() { QMessageBox::information(this, "Classroom Subject", "Classroom Subject Entry"); }
void MainWindow::on_actionTimeslot_triggered() { QMessageBox::information(this, "Timeslot", "Timeslot Entry"); }
void MainWindow::on_actionPreferredTime_triggered() { QMessageBox::information(this, "Preferred Time", "Preferred Time Entry"); }
void MainWindow::on_actionUnavailableTime_triggered() { QMessageBox::information(this, "Unavailable Time", "Unavailable Time Entry"); }

void MainWindow::restartApplication()
{
    QString program = QCoreApplication::applicationFilePath();
    QStringList args = QCoreApplication::arguments();
    QProcess::startDetached(program, args);
    QCoreApplication::exit(0);
}
