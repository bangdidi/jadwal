#include "LanguageUtil.h"
#include <QLocale>
#include <QFile>
#include <QCoreApplication>

namespace LanguageUtil {

bool loadTranslator(const QString &languageCode, QTranslator *translator)
{
    if (!translator) return false;

    const QString fileName = QString(":/i18n/menu_%1.qm").arg(languageCode);

    if (QFile::exists(fileName)) {
        return translator->load(fileName) && QCoreApplication::installTranslator(translator);
    }

    return false;
}

QString getLanguageName(const QString &code)
{
    if (code == "en") return "English";
    if (code == "id") return "Bahasa Indonesia";
    return "Unknown";
}

} // namespace LanguageUtil
