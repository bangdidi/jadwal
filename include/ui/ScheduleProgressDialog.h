#ifndef SCHEDULEPROGRESSDIALOG_H
#define SCHEDULEPROGRESSDIALOG_H

#include <QDialog>

namespace Ui { class ScheduleProgressDialog; }

class ScheduleProgressDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScheduleProgressDialog(QWidget *parent = nullptr);
    ~ScheduleProgressDialog();

public slots:
    void updateProgress(int percent);                // Update nilai progress bar
    void appendLogMessage(const QString &message);   // Tambah pesan log ke tampilan
    void onFinished(bool success);                   // Tangani proses selesai

signals:
    void cancelRequested();          // Sinyal jika user membatalkan proses
    void dialogFinished(bool success); // Sinyal jika dialog selesai (berhasil/gagal/cancel)

protected:
    void closeEvent(QCloseEvent *event) override;    // Proteksi penutupan dialog

private slots:
    void on_buttonCancel_clicked();                  // Handler tombol Cancel

private:
    bool m_finished = false;                         // Status selesai proses
    Ui::ScheduleProgressDialog *ui;
};

#endif // SCHEDULEPROGRESSDIALOG_H
