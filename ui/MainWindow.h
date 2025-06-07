#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "GeneticAlgorithm.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionNewProject_triggered();
    void on_actionOpenProject_triggered();
    void on_actionSaveProject_triggered();
    void on_actionSaveProjectAs_triggered();
    void on_actionSetting_triggered();
    void on_actionExit_triggered();
    void on_actionPreferredTime_triggered();
    void on_actionUnavailableTime_triggered();
    void on_actionImport_triggered();
    void on_actionSubject_triggered();
    void on_actionTeacher_triggered();
    void on_actionClassroom_triggered();
    void on_actionClassroomSubject_triggered();
    void on_actionClassroomTeacher_triggered();
    void on_actionTimeslot_triggered();
    void on_actionGenerate_triggered();
    void on_actionAbout_triggered();

    void onConfigurationReady(const QString &algorithm, const QVariantMap &config);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
