#include "core/ApplicationManager.h"
#include "utils/LanguageUtil.h"

#include <QCoreApplication>

ApplicationManager::ApplicationManager(QObject *parent)
    : QObject(parent)
{
}

ApplicationManager::~ApplicationManager()
{
    delete m_settings;
}

void ApplicationManager::initialize()
{
    m_settings = new QSettings("config.ini", QSettings::IniFormat);
    loadConfig();
    setupTranslator();
}

void ApplicationManager::loadConfig()
{
    m_language = m_settings->value("application/language", "en_US").toString();
    m_algorithm = m_settings->value("application/algorithm", "genetic").toString();
    m_timeLimit = m_settings->value("application/time_limit", 60).toInt();
}

void ApplicationManager::setupTranslator()
{
    if (LanguageUtil::loadTranslator(m_language, &m_translator)) {
        QCoreApplication::installTranslator(&m_translator);
    }
}

QString ApplicationManager::language() const
{
    return m_language;
}

QString ApplicationManager::algorithm() const
{
    return m_algorithm;
}

int ApplicationManager::timeLimit() const
{
    return m_timeLimit;
}

void ApplicationManager::setLanguage(const QString &language)
{
    if (m_language != language) {
        m_language = language;
        m_settings->setValue("application/language", m_language);
        emit languageChanged(m_language);
    }
}

void ApplicationManager::saveConfig()
{
    m_settings->setValue("application/algorithm", m_algorithm);
    m_settings->setValue("application/time_limit", m_timeLimit);
    m_settings->sync();
}

QSettings* ApplicationManager::settings()
{
    return m_settings;
}

QTranslator* ApplicationManager::translator()
{
    return &m_translator;
}
