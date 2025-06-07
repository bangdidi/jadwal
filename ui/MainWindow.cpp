#include "MainWindow.h"
#include "GenerateDialog.h"
#include "AboutDialog.h"
#include "ProcessPage.h"
#include "BacktrackingAlgorithm.h"
#include "ConstraintAlgorithm.h"
#include "GeneticAlgorithm.h"
#include "ui_MainWindow.h"

#include <QThread>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNewProject_triggered()
{
    QMessageBox::information(this, "NewProject", "NewProject triggered.");
}

void MainWindow::on_actionOpenProject_triggered()
{
    QMessageBox::information(this, "Open Project", "Open Project triggered.");
}

void MainWindow::on_actionSaveProject_triggered()
{
    QMessageBox::information(this, "Save Project", "Save Project triggered.");
}

void MainWindow::on_actionSaveProjectAs_triggered()
{
    QMessageBox::information(this, "Save Project as", "Save Project as triggered.");
}

void MainWindow::on_actionSetting_triggered()
{
    QMessageBox::information(this, "Setting", "Setting triggered.");
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

void MainWindow::on_actionPreferredTime_triggered()
{
    QMessageBox::information(this, "Preferred Time", "Preferred Time triggered.");
}

void MainWindow::on_actionUnavailableTime_triggered()
{
    QMessageBox::information(this, "Unavailable Time", "Unavailable Time triggered.");
}

void MainWindow::on_actionImport_triggered()
{
    QMessageBox::information(this, "Import", "Import triggered.");
}

void MainWindow::on_actionSubject_triggered()
{
    QMessageBox::information(this, "Subject", "Subject triggered.");
}

void MainWindow::on_actionTeacher_triggered()
{
    QMessageBox::information(this, "Teacher", "Teacher triggered.");
}

void MainWindow::on_actionClassroom_triggered()
{
    QMessageBox::information(this, "Classroom", "Classroom triggered.");
}

void MainWindow::on_actionClassroomSubject_triggered()
{
    QMessageBox::information(this, "Classroom's Subject", "Classroom Subject triggered.");
}

void MainWindow::on_actionClassroomTeacher_triggered()
{
    QMessageBox::information(this, "Classroom's Teacher", "Classroom's Teacher triggered.");
}

void MainWindow::on_actionTimeslot_triggered()
{
    QMessageBox::information(this, "Timeslot", "Timeslot triggered.");
}

void MainWindow::on_actionGenerate_triggered()
{
    GenerateDialog generateDialog(this);
    connect(&generateDialog, &GenerateDialog::configurationReady,
            this, &MainWindow::onConfigurationReady);
    generateDialog.exec();
}


void MainWindow::on_actionAbout_triggered()
{
    AboutDialog aboutDialog(this);
    aboutDialog.exec();
}

void MainWindow::onConfigurationReady(const QString &algorithm, const QVariantMap &config)
{
    if (algorithm == "BACKTRACKING") {
        BacktrackingAlgorithm backtrackingAlgorithm;
        backtrackingAlgorithm.init(config);
        backtrackingAlgorithm.run();
    } else if (algorithm == "CONSTRAINT") {
        ConstraintAlgorithm constraintAlgorithm;
        constraintAlgorithm.init(config);
        constraintAlgorithm.run();
    } else if (algorithm == "GENETIC") {
        auto *processPage = new ProcessPage();
        ui->stackedWidget->addWidget(processPage);
        ui->stackedWidget->setCurrentWidget(processPage);

        auto *thread = new QThread(this);
        auto *algorithmWorker = new GeneticAlgorithm();

        algorithmWorker->init(config);
        algorithmWorker->moveToThread(thread);

        connect(thread, &QThread::started, algorithmWorker, &GeneticAlgorithm::run);
        connect(algorithmWorker, &GeneticAlgorithm::progressChanged,
                processPage, &ProcessPage::updateProgress);
        connect(algorithmWorker, &GeneticAlgorithm::logMessage,
                processPage, &ProcessPage::logMessage);
        connect(algorithmWorker, &GeneticAlgorithm::finished, thread, &QThread::quit);
        connect(algorithmWorker, &GeneticAlgorithm::finished,
                processPage, &ProcessPage::onFinished);

        connect(thread, &QThread::finished, algorithmWorker, &QObject::deleteLater);
        connect(thread, &QThread::finished, thread, &QObject::deleteLater);

        connect(processPage, &ProcessPage::cancelRequested,
                algorithmWorker, &GeneticAlgorithm::requestCancel);

        thread->start();
    }
}
