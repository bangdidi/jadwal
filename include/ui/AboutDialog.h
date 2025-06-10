#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QDialog>

class QLabel;
class QPushButton;

class AboutDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AboutDialog(QWidget *parent = nullptr);

private:
    QLabel *infoLabel;
    QPushButton *okButton;
};

#endif // ABOUTDIALOG_H