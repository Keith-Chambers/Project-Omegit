#include "util.h"

Util::Util()
{

}

QJsonDocument Util::readJson(QString url)
{
    QString val;
    QFile file;
    file.setFileName(url);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    val = file.readAll();
    file.close();

    return QJsonDocument::fromJson(val.toUtf8());
}
