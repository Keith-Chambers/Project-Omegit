#ifndef CONFIG_H
#define CONFIG_H

#include <QHash>
#include <QString>
#include <QUrl>

namespace config
{
    extern QUrl apiUrl;
    extern QHash<QString, QString> endPoints;
    extern QString jsonClientInfoPath;
    extern qint64 chatPollFreqMilliSecs;
}
#endif // CONFIG_H
