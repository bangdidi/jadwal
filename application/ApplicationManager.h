#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include <QObject>
#include <memory>

class ConfigurationManager;
class MainWindow;
class QApplication;

class ApplicationManager : public QObject
{
    Q_OBJECT

public:
    ApplicationManager(QApplication *app, QObject *parent = nullptr);
    ~ApplicationManager();

    void run();

private:
    QApplication *app;
    std::unique_ptr<ConfigurationManager> configManager;
    std::unique_ptr<MainWindow> mainWindow;
};

#endif // APPLICATION_MANAGER_H
