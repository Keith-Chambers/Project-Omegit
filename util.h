#ifndef UTIL_H
#define UTIL_H

#include <QJsonDocument>
#include <QFile>
#include <QIODevice>

class Util
{
public:
    Util();
    static QJsonDocument readJson(QString url);
};

#endif // UTIL_H
