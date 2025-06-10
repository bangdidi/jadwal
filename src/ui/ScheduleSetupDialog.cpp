#include "ScheduleSetupDialog.h"
#include "ui_ScheduleSetupDialog.h"

# include <QDebug>

ScheduleSetupDialog::ScheduleSetupDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ScheduleSetupDialog)
{
    ui->setupUi(this);

    connect(ui->tabWidget, &QTabWidget::currentChanged, this, &ScheduleSetupDialog::onTabChanged);

    connect(ui->buttonBacktrackingGenerate, &QPushButton::clicked, this, &ScheduleSetupDialog::handleGenerateClicked);
    connect(ui->buttonConstraintGenerate, &QPushButton::clicked, this, &ScheduleSetupDialog::handleGenerateClicked);
    connect(ui->buttonGeneticGenerate, &QPushButton::clicked, this, &ScheduleSetupDialog::handleGenerateClicked);

    connect(ui->buttonBacktrackingCancel, &QPushButton::clicked, this, &ScheduleSetupDialog::reject);
    connect(ui->buttonConstraintCancel, &QPushButton::clicked, this, &ScheduleSetupDialog::reject);
    connect(ui->buttonGeneticCancel, &QPushButton::clicked, this, &ScheduleSetupDialog::reject);

    onTabChanged(ui->tabWidget->currentIndex());
}

ScheduleSetupDialog::~ScheduleSetupDialog()
{
    delete ui;
}

void ScheduleSetupDialog::onTabChanged(int index) {
    QWidget* currentTab = ui->tabWidget->widget(index);

    if (currentTab == ui->tabBacktracking) {
        ui->buttonBacktrackingGenerate->setFocus();
    } else if (currentTab == ui->tabConstraint) {
        ui->buttonConstraintGenerate->setFocus();
    } else if (currentTab == ui->tabGenetic) {
        ui->buttonGeneticGenerate->setFocus();
    }
}


void ScheduleSetupDialog::handleGenerateClicked()
{
    m_config = QVariantMap();
    m_config.clear();

    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    if (button == ui->buttonBacktrackingGenerate) {
        m_selectedAlgorithm = "BACKTRACKING";
        m_config["timeout"] = ui->spinBacktrackingTimeout->value();
        m_config["forwardChecking"] = ui->checkboxBacktrackingForwardChecking->isChecked();
        m_config["variableOrdering"] = ui->comboBacktrackingVariableOrdering->currentText();
        m_config["valueOrdering"] = ui->comboBacktrackingValueOrdering->currentText();
        m_config["enablePruning"] = ui->checkboxBacktrackingEnablePruning->isChecked();
        m_config["maxBacktracks"] = ui->spinBacktrackingMaxBacktracks->value();
    } else if (button == ui->buttonConstraintGenerate) {
        m_selectedAlgorithm = "CONSTRAINT";
        m_config["timeout"] = ui->spinConstraintTimeout->value();
        m_config["variableOrdering"] = ui->comboConstraintVariableOrdering->currentText();
        m_config["valueOrdering"] = ui->comboConstraintValueOrdering->currentText();
        m_config["propagation"] = ui->comboConstraintPropagation->currentText();
        m_config["maxBacktracks"] = ui->spinConstraintMaxBacktracks->value();
    } else if (button == ui->buttonGeneticGenerate) {
        m_selectedAlgorithm = "GENETIC";
        m_config["timeout"] = ui->spinGeneticTimeout->value();
        m_config["populationSize"] = ui->spinGeneticPopulation->value();
        m_config["crossoverRate"] = ui->spinGeneticCrossover->value();
        m_config["mutationRate"] = ui->spinGeneticMutation->value();
        m_config["maxGenerations"] = ui->spinGeneticMaxGenerations->value();
        m_config["conflictPenalty"] = ui->spinGeneticConflictPenalty->value();
        m_config["unavailablePenalty"] = ui->spinGeneticUnavailablePenalty->value();
        m_config["preferredPenalty"] = ui->spinGeneticPreferredPenalty->value();
        m_config["fitnessFunction"] = ui->comboGeneticFitnessFunction->currentText();
    }

    emit configurationReady(m_selectedAlgorithm, m_config);
    accept();
}

QString ScheduleSetupDialog::selectedAlgorithm() const
{
    return m_selectedAlgorithm; // Pastikan variabel ini ada dan di-set saat dialog Accepted
}

QVariantMap ScheduleSetupDialog::config() const
{
    return m_config;
}