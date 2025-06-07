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

    infoLabel = new QLabel(QStringLiteral("This is MyApp version 1.0\n\u00A9 2025 Your Name"));
    infoLabel->setAlignment(Qt::AlignCenter);

    okButton = new QPushButton("OK");
    connect(okButton, &QPushButton::clicked, this, &AboutDialog::accept);

    layout->addWidget(infoLabel);
    layout->addWidget(okButton);
    setLayout(layout);
}
