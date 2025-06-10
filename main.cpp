#include "ApplicationManager.h"
#include "MainWindow.h"

#include <QApplication>
#include <QSettings>
#include <QTranslator>
#include <QLocale>
#include <QDebug>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    QSettings settings("config.ini", QSettings::IniFormat);

    QString language = settings.value("application/language", "en_US").toString();
    QTranslator translator;
    QString translationPath = QString(":/i18n/%1.qm").arg(language);
    if (!translator.load(translationPath)) {
        qDebug() << "Failed to load translation:" << translationPath;
    } else {
        app.installTranslator(&translator);
    }

    ApplicationManager appManager;
    appManager.initialize();

    MainWindow window(&appManager);
    window.show();

    return app.exec();
}
