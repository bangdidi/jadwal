#ifndef APPLICATIONMANAGER_H
#define APPLICATIONMANAGER_H

#include <QObject>
#include <QSettings>
#include <QTranslator>

// Manajer aplikasi untuk konfigurasi global, bahasa, dan pengaturan
class ApplicationManager : public QObject
{
    Q_OBJECT
public:
    explicit ApplicationManager(QObject *parent = nullptr);
    ~ApplicationManager();

    void initialize();

    QString language() const;
    QString algorithm() const;
    int timeLimit() const;

    void setLanguage(const QString &language);
    void saveConfig();

    QSettings* settings();
    QTranslator* translator();

signals:
    void languageChanged(const QString &language);

private:
    void loadConfig();
    void setupTranslator();

    QSettings *m_settings = nullptr;
    QTranslator m_translator;

    QString m_language;
    QString m_algorithm;
    int m_timeLimit;
};

#endif // APPLICATIONMANAGER_H
