#include "guicontrollayer.h"

GuiControlLayer::GuiControlLayer(QJsonDocument pClientInfo, QObject *parent)
    : QObject(parent), mClientInfo(pClientInfo)
{

}

bool GuiControlLayer::registerUser(QString pUsername, QString pPassword,
                                   QString pEmailPrefix, QString pEmailSuffix)
{
    RegistrationDetails registrationDetails;
    QCryptographicHash hash(QCryptographicHash::Algorithm::Sha256);
    hash.addData(pPassword.toLocal8Bit());

    registrationDetails.emailPrefix = pEmailPrefix;
    registrationDetails.emailSuffix = pEmailSuffix.section(QChar(' '), 0, 0);
    registrationDetails.username = pUsername;


    registrationDetails.password = QString(QCryptographicHash::hash(pPassword.toLocal8Bit(),
                                          QCryptographicHash::Sha256).toHex());

    DiTalkRegistration registration(mClientInfo, registrationDetails);

    qDebug() << QString("Username: ") + pUsername;
    qDebug() << QString("Password: ") + pPassword;
    qDebug() << QString("Email: ") + pEmailPrefix + registrationDetails.emailSuffix;

    return registration.attemptRegistration();
}

bool GuiControlLayer::loginUser(QString pUsername, QString pPassword)
{
    mUserSession.login(pUsername, pPassword);

    QObject::connect(&mUserSession, SIGNAL(loginProcessed(bool)), this, SLOT(relayLoggedIn(bool)));
    return true;
}

bool GuiControlLayer::isLoggedIn()
{
    qDebug() << "isLoggedIn called - " << mUserSession.isLoggedIn();
    return mUserSession.isLoggedIn();
}

// TODO: Remove GuiControlLayer to get rid of this kind of silliness
void GuiControlLayer::relayLoggedIn(bool pIsLoggedIn)
{
    qDebug() << "Emitting logginChanged";
    emit loggedInChanged(pIsLoggedIn);
    qDebug() << "Logged in: " << isLoggedIn();
}
