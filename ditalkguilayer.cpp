#include "ditalkguilayer.h"

DitalkGuiLayer::DitalkGuiLayer(DitalkBackendController &pBackend, QObject *parent) :
    mBackend(pBackend), QObject(parent)
{
    QObject::connect(&mBackend, SIGNAL(stateChanged(DitalkState::State)),
                     this, SIGNAL(stateChanged(DitalkState::State)));

    QObject::connect(&mBackend, SIGNAL(stateChanged(DitalkState::State)),
                     this, SLOT(onStateChanged(DitalkState::State)));

}

void DitalkGuiLayer::onStateChanged(DitalkState::State pNewState)
{
    switch(pNewState)
    {
    case DitalkState::State::LoggedOut:
        mFrontEndState.applicationHeight = 400;
        mFrontEndState.applicationWidth = 350;
        break;
    case DitalkState::State::LoggedIn:
    case DitalkState::State::Chatting:
        mFrontEndState.applicationHeight = 580;
        mFrontEndState.applicationWidth = 640;
        break;
    default:
        qDebug() << "Warning: Invalid State passed to DitalkGuiLayer::onStateChanged()";
    }

    emit appHeightChanged();
    emit appWidthChanged();
}

void DitalkGuiLayer::registerUser(QString pUsername, QString pPassword,
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

    mBackend.registerAccount(registrationDetails);

    qDebug() << QString("Username: ") + pUsername;
    qDebug() << QString("Password: ") + pPassword;
    qDebug() << QString("Email: ") + pEmailPrefix + registrationDetails.emailSuffix;
}

void DitalkGuiLayer::startChat()
{
    mBackend.newChat();
}

void DitalkGuiLayer::login(QString pUsername, QString pPassword)
{
    mBackend.login(pUsername, pPassword);
}

DitalkState::State DitalkGuiLayer::getState()
{
    return mBackend.getState();
}

int DitalkGuiLayer::getAppWidth()
{
    return mFrontEndState.applicationWidth;
}

int DitalkGuiLayer::getAppHeight()
{
    return mFrontEndState.applicationHeight;
}

void DitalkGuiLayer::sendMessage(QString pMessage)
{
    mBackend.sendMessage(pMessage);
}





















