#ifndef CONFIGURATION_MANAGER_H
#define CONFIGURATION_MANAGER_H

#include <QString>
#include <QVariant>
#include <QMap>

class ConfigurationManager
{
public:
    ConfigurationManager();

    bool load();
    QVariant get(const QString &key, const QVariant &defaultValue = {}) const;
    void set(const QString &key, const QVariant &value);
    void save() const;

private:
    QString configPath;
    QMap<QString, QVariant> settings;
};

#endif // CONFIGURATION_MANAGER_H
