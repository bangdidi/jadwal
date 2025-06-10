#ifndef SETTINGDIALOG_H
#define SETTINGDIALOG_H

#include <QDialog>
#include <QSettings>

QT_BEGIN_NAMESPACE
namespace Ui { class SettingDialog; }
QT_END_NAMESPACE

class SettingDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SettingDialog(QWidget *parent = nullptr);
    ~SettingDialog();

    void loadSettings(QSettings *settings);
    void saveSettings(QSettings *settings) const;

private:
    Ui::SettingDialog *ui;
};

#endif // SETTINGDIALOG_H
