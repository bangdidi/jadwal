#include "GenerateDialog.h"
#include "ui_GenerateDialog.h"

# include <QDebug>

static bool connected = false;
GenerateDialog::GenerateDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::GenerateDialog)
{
    ui->setupUi(this);

    connect(ui->buttonBacktrackingGenerate, &QPushButton::clicked, this, &GenerateDialog::handleGenerateClicked);
    connect(ui->buttonConstraintGenerate, &QPushButton::clicked, this, &GenerateDialog::handleGenerateClicked);
    connect(ui->buttonGeneticGenerate, &QPushButton::clicked, this, &GenerateDialog::handleGenerateClicked);

    connect(ui->buttonBacktrackingCancel, &QPushButton::clicked, this, &GenerateDialog::reject);
    connect(ui->buttonConstraintCancel, &QPushButton::clicked, this, &GenerateDialog::reject);
    connect(ui->buttonGeneticCancel, &QPushButton::clicked, this, &GenerateDialog::reject);
}

GenerateDialog::~GenerateDialog()
{
    delete ui;
}

void GenerateDialog::handleGenerateClicked()
{
    m_config = QVariantMap();
    m_config.clear();

    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (!button) return;

    if (button == ui->buttonBacktrackingGenerate) {
        m_algorithm = "BACKTRACKING";
        m_config["timeout"] = ui->spinBacktrackingTimeout->value();
        m_config["forwardChecking"] = ui->checkboxBacktrackingForwardChecking->isChecked();
        m_config["variableOrdering"] = ui->comboBacktrackingVariableOrdering->currentText();
        m_config["valueOrdering"] = ui->comboBacktrackingValueOrdering->currentText();
        m_config["enablePruning"] = ui->checkboxBacktrackingEnablePruning->isChecked();
        m_config["maxBacktracks"] = ui->spinBacktrackingMaxBacktracks->value();
    } else if (button == ui->buttonConstraintGenerate) {
        m_algorithm = "CONSTRAINT";
        m_config["timeout"] = ui->spinConstraintTimeout->value();
        m_config["variableOrdering"] = ui->comboConstraintVariableOrdering->currentText();
        m_config["valueOrdering"] = ui->comboConstraintValueOrdering->currentText();
        m_config["propagation"] = ui->comboConstraintPropagation->currentText();
        m_config["maxBacktracks"] = ui->spinConstraintMaxBacktracks->value();
    } else if (button == ui->buttonGeneticGenerate) {
        m_algorithm = "GENETIC";
        m_config["timeout"] = ui->spinGeneticTimeout->value();
        m_config["populationSize"] = ui->spinGeneticPopulation->value();
        m_config["crossoverRate"] = ui->spinGeneticCrossover->value();
        m_config["mutationRate"] = ui->spinGeneticMutation->value();
        m_config["maxGenerations"] = ui->spinGeneticMaxGenerations->value();
        m_config["conflictPenalty"] = ui->spinGeneticConflictPenalty->value();
        m_config["unavailablePenalty"] = ui->spinGeneticUnavailablePenalty->value();
        m_config["preferredPenalty"] = ui->spinGeneticPreferredPenalty->value();
        m_config["fitnessFunction"] = ui->comboGeneteciFitnessFunction->currentText();
    }

    emit configurationReady(m_algorithm, m_config);
    accept();
}
