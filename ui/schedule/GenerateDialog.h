#ifndef GENERATEDIALOG_H
#define GENERATEDIALOG_H

#include <QDialog>
#include <QVariantMap>

namespace Ui {
class GenerateDialog;
}

class GenerateDialog : public QDialog
{
    Q_OBJECT

public:
    explicit GenerateDialog(QWidget *parent = nullptr);
    ~GenerateDialog();

signals:
    void configurationReady(const QString &algorithm, const QVariantMap &config);

private slots:
    void handleGenerateClicked();

private:
    Ui::GenerateDialog *ui;
    QString m_algorithm;
    QVariantMap m_config;
};

#endif // GENERATEDIALOG_H
