#ifndef SCHEDULESETUPDIALOG_H
#define SCHEDULESETUPDIALOG_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class ScheduleSetupDialog;
}

class ScheduleSetupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ScheduleSetupDialog(QWidget *parent = nullptr);
    ~ScheduleSetupDialog();

    QString selectedAlgorithm() const;
    QVariantMap config() const;

signals:
    void configurationReady(const QString &algorithm, const QVariantMap &config);

private slots:
    void onTabChanged(int index);
    void handleGenerateClicked();

private:
    Ui::ScheduleSetupDialog *ui;
    QString m_selectedAlgorithm;
    QVariantMap m_config;
};

#endif // SCHEDULESETUPDIALOG_H