#include "ditalkbackendcontroller.h"

DitalkBackendController::DitalkBackendController(QQmlApplicationEngine *pEngine, QObject *parent) :
    mNetConnection(), mUserRecord(), mState(DitalkState::State::LoggedOut), mCookieJar(),
    mChatManager(pEngine, mNetConnection, this), QObject(parent)
{
    mEngine = pEngine;

    QObject::connect(&mChatManager, SIGNAL(newChatEstablished()), this, SLOT(onNewChat()));
    QObject::connect(&mChatManager, SIGNAL(chatDisconnected()), this, SLOT(onChatDisconnected()));
}

void DitalkBackendController::registerAccount(RegistrationDetails pRegistrationDetails)
{
    qDebug() << "Starting registration process";

    QJsonDocument clientInfoDoc = Util::readJson(QString(config::jsonClientInfoPath));

    const QJsonObject clientInfoTempObj = clientInfoDoc.object();
    const QJsonObject clientInfoObj = clientInfoTempObj["web"].toObject();

    const QString clientId = clientInfoObj["client_id"].toString();
    const QJsonArray redirectPathArray = clientInfoObj["redirect_uris"].toArray();
    const QUrl redirectUri(QString(redirectPathArray.at(0).toString()));

    QString state {"username=" + pRegistrationDetails.username +
                ";password=" + pRegistrationDetails.password +
                ";emailPrefix=" + pRegistrationDetails.emailPrefix +
                ";emailSuffix=" + pRegistrationDetails.emailSuffix};

    qDebug() << "State: " + state;

    QString scope {"openid profile https://www.googleapis.com/auth/plus.login https://www.googleapis.com/auth/userinfo.email"};

    QString authBuildString {   QString("https://accounts.google.com/o/oauth2/auth?") +
                                QString("client_id=") + clientId +
                                QString("&redirect_uri=") + redirectUri.toString() +
                                QString("&response_type=code") +
                                QString("&scope=") + scope +
                                QString("&state=") + state};

    QDesktopServices::openUrl(QUrl(authBuildString));
}

bool DitalkBackendController::login(QString pUsername, QString pPassword)
{
    // TODO: Add more constraints
    if(pUsername.isEmpty() || pPassword.isEmpty())
    {
        qDebug() << "Insufficient user information to perform login request";
        return false;
    }

    mUserRecord.username = pUsername;
    QString password = QString(QCryptographicHash::hash(pPassword.toLocal8Bit(),
                                                            QCryptographicHash::Sha256).toHex());

    qDebug() << mUserRecord.username;
    qDebug() << password;

    QByteArray postData;
    QString param1 {"username=" + mUserRecord.username + "&"};
    QString param2 {"password=" + password };

    postData.append(param1.toLocal8Bit());
    postData.append(param2.toLocal8Bit());

    // TODO: See can you make this less inefficient
    QNetworkRequest request(QUrl(config::apiUrl.toString() + config::endPoints["login"]));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    mNetConnection.disconnect();
    QObject::connect(&mNetConnection, SIGNAL(finished(QNetworkReply*)),
                     this, SLOT(loginResponse(QNetworkReply *)));

    mNetConnection.post(request, postData);

    qDebug() << "Request to login sent";

    return true;
}

DitalkState::State DitalkBackendController::getState()
{
    return mState;
}

bool DitalkBackendController::sendMessage(QString pMessage)
{
    if(mState != DitalkState::State::Chatting)
    {
        qDebug() << "No open chat to send message to";
        return false;
    }

    mChatManager.newOutgoingMessage(pMessage);
    return true;
}

bool DitalkBackendController::newChat()
{
    if(mState != DitalkState::State::LoggedIn)
    {
        qDebug() << "You must be logged in and have no existing chat to start a new chat";
        return false;
    }

    mChatManager.startChat();
    return true;
}

void DitalkBackendController::onNewChat()
{
    mState = DitalkState::State::Chatting;
    emit stateChanged(mState);
}

void DitalkBackendController::onChatDisconnected()
{
    mState = DitalkState::State::LoggedIn;
    emit stateChanged(mState);
}

void DitalkBackendController::logout()
{
    if(mUserRecord.sessionID.isEmpty())
    {
        qDebug() << "Failed to logout, no active session found";
        return;
    }

    QByteArray postData;
    QString param1 {"sessionId=" + mUserRecord.sessionID};

    postData.append(param1.toLocal8Bit());

    QNetworkRequest request(QUrl(config::apiUrl.toString() + config::endPoints["logout"]));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    mNetConnection.disconnect();
    QObject::connect(&mNetConnection, SIGNAL(finished(QNetworkReply*)),
                     this, SLOT(logoutResponse(QNetworkReply *)));
    mNetConnection.post(request, postData);

    qDebug() << "Request to logout current user completed";
}

void DitalkBackendController::loginResponse(QNetworkReply* reply)
{
    QString rawJsonResponse {reply->readAll()};

    //qDebug() << "Raw Json: " + rawJsonResponse;

    QJsonDocument json;
    json = QJsonDocument::fromJson(rawJsonResponse.toUtf8());

    if(json.isNull())
    {
        qDebug() << "Invalid Json received";
        return;
    }

    QJsonObject jsonObject = json.object();

    if(jsonObject["sessionID"].toString().isEmpty())
    {
        qDebug() << "No session id found, failed to log in";
        return;
    }

    mUserRecord.sessionID = jsonObject["sessionID"].toString();

    QString cookieName {"PHPSESSID"};
    QString cookieValue { mUserRecord.sessionID };
    QNetworkCookie cookie(cookieName.toLocal8Bit(), cookieValue.toLocal8Bit());
    cookie.setDomain(QString("ditalk.xyz"));
    mCookieJar.insertCookie(cookie);

    mState = DitalkState::State::LoggedIn;
    emit stateChanged(mState);

    qDebug() << "Login response received";
}

void DitalkBackendController::logoutResponse(QNetworkReply* reply)
{
    qDebug() << reply->readAll();
    qDebug() << "Successfully logged out";
    mState = DitalkState::State::LoggedOut;
    emit stateChanged(mState);
}
