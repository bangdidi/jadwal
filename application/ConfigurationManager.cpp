#include "ConfigurationManager.h"
#include <QCoreApplication>
#include <QSettings>
#include <QFileInfo>
#include <QDebug>

ConfigurationManager::ConfigurationManager()
{
    QString exeDir = QCoreApplication::applicationDirPath();
    configPath = exeDir + "/config.ini";
}

bool ConfigurationManager::load()
{
    if (!QFileInfo::exists(configPath))
    {
        qWarning() << "Configuration file not found:" << configPath;
        return false;
    }

    QSettings settingsFile(configPath, QSettings::IniFormat);
    const QStringList keys = settingsFile.allKeys();
    for (const QString &key : keys)
    {
        settings[key] = settingsFile.value(key);
    }

    return true;
}

QVariant ConfigurationManager::get(const QString &key, const QVariant &defaultValue) const
{
    return settings.value(key, defaultValue);
}

void ConfigurationManager::set(const QString &key, const QVariant &value)
{
    settings[key] = value;
}

void ConfigurationManager::save() const
{
    QSettings settingsFile(configPath, QSettings::IniFormat);
    for (auto it = settings.constBegin(); it != settings.constEnd(); ++it)
    {
        settingsFile.setValue(it.key(), it.value());
    }
}
