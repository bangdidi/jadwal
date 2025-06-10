#ifndef SCHEDULEPROGRESSDIALOG_H
#define SCHEDULEPROGRESSDIALOG_H

#include <QDialog>
#include <QCloseEvent>

namespace Ui { class ScheduleProgressDialog; }

class ScheduleProgressDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScheduleProgressDialog(QWidget *parent = nullptr);
    ~ScheduleProgressDialog();

public slots:
    void updateProgress(int percent);
    void appendLogMessage(const QString &message);
    void onFinished(bool success);

signals:
    void cancelRequested();
    void dialogFinished(bool success);

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_buttonCancel_clicked();

private:
    bool m_finished = false;
    Ui::ScheduleProgressDialog *ui;
};

#endif // SCHEDULEPROGRESSDIALOG_H
