#include "ditalkguilayer.h"

DitalkGuiLayer::DitalkGuiLayer(DitalkBackendController &pBackend, QObject *parent) :
    mBackend(pBackend), QObject(parent)
{
    QObject::connect(&mBackend, SIGNAL(stateChanged(DitalkState::State)),
                     this, SIGNAL(stateChanged(DitalkState::State)));

    QObject::connect(&mBackend, SIGNAL(stateChanged(DitalkState::State)),
                     this, SLOT(onStateChanged(DitalkState::State)));

    QObject::connect(&mBackend, SIGNAL(usernameChanged()),
                     this, SIGNAL(usernameChanged()));
    QObject::connect(&mBackend, SIGNAL(firstNameChanged()),
                     this, SIGNAL(firstNameChanged()));
    QObject::connect(&mBackend, SIGNAL(lastNameChanged()),
                     this, SIGNAL(lastNameChanged()));
    QObject::connect(&mBackend, SIGNAL(fullNameChanged()),
                     this, SIGNAL(fullNameChanged()));

    QObject::connect(&mBackend, SIGNAL(startChatFailed()), this, SLOT(onStartChatFailed()));
}

void DitalkGuiLayer::onStartChatFailed()
{
    qDebug() << "onStartChatFailed called";
    mWaiting = false;
    emit waitingChanged(mWaiting);
}

bool DitalkGuiLayer::getWaiting()
{
    qDebug() << "Get waiting";
    return mWaiting;
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
        mFrontEndState.applicationHeight = 520;
        mFrontEndState.applicationWidth = 500;
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
    mWaiting = true;
    emit waitingChanged(mWaiting);
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

QString DitalkGuiLayer::getUsername()
{
    return mBackend.getUsername();
}

QString DitalkGuiLayer::getFirstName()
{
    return mBackend.getFirstName();
}

QString DitalkGuiLayer::getLastName()
{
    return mBackend.getLastName();
}

QString DitalkGuiLayer::getFullName()
{
    qDebug() << "Full name: " + mBackend.getFullName();
    return mBackend.getFullName();
}

void DitalkGuiLayer::logout()
{
    qDebug() << "Logging out";
    mBackend.logout();
}

















