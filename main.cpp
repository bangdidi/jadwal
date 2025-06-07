#include <QApplication>
#include <QCoreApplication>
#include "ApplicationManager.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_DisableSessionManager);
    QApplication app(argc, argv);
    ApplicationManager manager(&app);
    manager.run();

    return app.exec();
}
