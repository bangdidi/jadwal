#ifndef LANGUAGEUTIL_H
#define LANGUAGEUTIL_H

#include <QString>
#include <QTranslator>

namespace LanguageUtil {

bool loadTranslator(const QString &languageCode, QTranslator *translator);

QString getLanguageName(const QString &code);

} // namespace LanguageUtil

#endif // LANGUAGEUTIL_H
