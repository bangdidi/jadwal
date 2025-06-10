#include "AboutDialog.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>

AboutDialog::AboutDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle("About");

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setContentsMargins(20, 20, 20, 20);
    layout->setSpacing(20);

    QString appName = tr("Schedule Generator");
    QString appVersion = "1.0";
    QString appYear = "2025";
    QString appAuthor = "NongBit";
    infoLabel = new QLabel(appName + " " + tr("version") + " " + appVersion + "\n" + QChar(0x00A9) + appYear + " " + appAuthor);
    infoLabel->setAlignment(Qt::AlignCenter);

    okButton = new QPushButton("OK");
    connect(okButton, &QPushButton::clicked, this, &AboutDialog::accept);

    layout->addWidget(infoLabel);
    layout->addWidget(okButton);
    setLayout(layout);
}