#ifndef DITALKREGISTRATION_H
#define DITALKREGISTRATION_H

#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDesktopServices>
#include <QUrl>
#include <QCryptographicHash>

typedef struct RegistrationDetails
{
    QString username;
    QString password;
    QString emailPrefix;
    QString emailSuffix;
} RegistrationDetails;

class DiTalkRegistration
{
public:
    DiTalkRegistration(QJsonDocument pClientInfo, RegistrationDetails pRegistrationDetails);
    bool validateRegistrationDetails();
    bool attemptRegistration();
signals:

public slots:

private:
    QJsonDocument mClientInfo;
    RegistrationDetails mRegistrationDetails;
};

#endif // DITALKREGISTRATION_H
