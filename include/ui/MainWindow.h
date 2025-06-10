#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class ApplicationManager;
class Scheduler;
class ScheduleSetupDialog;
class ScheduleProgressDialog;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(ApplicationManager *appManager, QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionSetting_triggered();
    void on_actionGenerate_triggered();
    void on_actionAbout_triggered();
    void on_actionExit_triggered();

    void on_actionNewProject_triggered();
    void on_actionOpenProject_triggered();
    void on_actionSaveProject_triggered();
    void on_actionSaveProjectAs_triggered();

    void on_actionImport_triggered();
    void on_actionSubject_triggered();
    void on_actionTeacher_triggered();
    void on_actionClassroom_triggered();
    void on_actionClassroomSubject_triggered();
    void on_actionTimeslot_triggered();
    void on_actionPreferredTime_triggered();
    void on_actionUnavailableTime_triggered();

    void onConfigurationReady(const QString &algorithm, const QVariantMap &config);
    void onScheduleFinished(bool success);

private:
    void restartApplication();

    Ui::MainWindow *ui;
    ApplicationManager *m_appManager;
    Scheduler *m_scheduler;
    ScheduleProgressDialog *m_progressDialog = nullptr;
};

#endif // MAINWINDOW_H
