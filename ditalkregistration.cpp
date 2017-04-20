#include "ditalkregistration.h"

DiTalkRegistration::DiTalkRegistration(QJsonDocument pClientInfo, RegistrationDetails pRegistrationDetails)
    : mClientInfo(pClientInfo), mRegistrationDetails(pRegistrationDetails)
{
    qDebug() << "DiTalkRegistration contructor called";

}

// TODO: Implement this
bool DiTalkRegistration::validateRegistrationDetails()
{
    return true;
}

bool DiTalkRegistration::attemptRegistration()
{
    qDebug() << "Starting registration process";

    if(!validateRegistrationDetails())
        return false;

    const QJsonObject clientInfoTempObj = mClientInfo.object();
    const QJsonObject clientInfoObj = clientInfoTempObj["web"].toObject();

    const QString clientId = clientInfoObj["client_id"].toString();
    const QJsonArray redirectPathArray = clientInfoObj["redirect_uris"].toArray();
    const QUrl redirectUri(QString(redirectPathArray.at(0).toString()));

    QString state {"username=" + mRegistrationDetails.username +
                ";password=" + mRegistrationDetails.password +
                ";emailPrefix=" + mRegistrationDetails.emailPrefix +
                ";emailSuffix=" + mRegistrationDetails.emailSuffix};

    qDebug() << "State: " + state;

    QString scope {"openid profile https://www.googleapis.com/auth/plus.login https://www.googleapis.com/auth/userinfo.email"};

    QString authBuildString {   QString("https://accounts.google.com/o/oauth2/auth?") +
                                QString("client_id=") + clientId +
                                QString("&redirect_uri=") + redirectUri.toString() +
                                QString("&response_type=code") +
                                QString("&scope=") + scope +
                                QString("&state=") + state};

    QDesktopServices::openUrl(QUrl(authBuildString));

    return true;
}
