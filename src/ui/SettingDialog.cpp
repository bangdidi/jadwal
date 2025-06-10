#include "SettingDialog.h"
#include "ui_SettingDialog.h"

SettingDialog::SettingDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::SettingDialog)
{
    ui->setupUi(this);

    ui->comboLanguage->setItemData(0, "id_ID");
    ui->comboLanguage->setItemData(1, "en_US");

    connect(ui->buttonBox, &QDialogButtonBox::accepted, this, &QDialog::accept);
    connect(ui->buttonBox, &QDialogButtonBox::rejected, this, &QDialog::reject);
}

SettingDialog::~SettingDialog() {
    delete ui;
}

void SettingDialog::loadSettings(QSettings *settings) {
    QString language = settings->value("application/language", "en_US").toString();
    if (language == "id_ID") {
        ui->comboLanguage->setCurrentIndex(0);
    } else if (language == "en_US") {
        ui->comboLanguage->setCurrentIndex(1);
    } else {
        ui->comboLanguage->setCurrentIndex(0);
    }
}

void SettingDialog::saveSettings(QSettings *settings) const {
    settings->setValue("application/language", ui->comboLanguage->currentData().toString());
}