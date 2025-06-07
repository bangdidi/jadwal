#include "ApplicationManager.h"
#include "ConfigurationManager.h"
#include "MainWindow.h"

#include <QObject>
#include <QDebug>

ApplicationManager::ApplicationManager(QApplication *app, QObject *parent)
    : QObject(parent), app(app),
      configManager(std::make_unique<ConfigurationManager>())
{
}

ApplicationManager::~ApplicationManager() = default;

void ApplicationManager::run()
{
    configManager->load();

    mainWindow = std::make_unique<MainWindow>();
    mainWindow->show();
}
