#include "usersession.h"

UserSession::UserSession(QObject *parent)
    : mNetConnection(), mNetworkState(NetworkState::NoConnection), QObject(parent)
{
    QObject::connect(&mNetConnection, SIGNAL(finished(QNetworkReply*)),
                     this, SLOT(handleNetworkResponse(QNetworkReply*)));
}

bool UserSession::login(QString pUsername, QString pPassword)
{
    // TODO: Add more constraints
    if(pUsername.isEmpty() || pPassword.isEmpty() || mUserRecord.loggedIn)
    {
        qDebug() << "Insufficient user information to perform login request";
        return false;
    }

    mUserRecord.username = pUsername;
    mUserRecord.password = QString(QCryptographicHash::hash(pPassword.toLocal8Bit(),
                                                            QCryptographicHash::Sha256).toHex());

    qDebug() << mUserRecord.username;
    qDebug() << mUserRecord.password;

    QByteArray postData;
    QString param1 {"username=" + mUserRecord.username + "&"};
    QString param2 {"password=" + mUserRecord.password };

    postData.append(param1.toLocal8Bit());
    postData.append(param2.toLocal8Bit());

    // TODO: See can you make this less inefficient
    QNetworkRequest request(QUrl(config::apiUrl.toString() + config::endPoints["login"]));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    mNetConnection.post(request, postData);

    qDebug() << "Request to login sent";

    mNetworkState = NetworkState::Login;

    return true;
}

void UserSession::logout()
{
    if(mUserRecord.sessionID.isEmpty())
    {
        qDebug() << "Failed to logout, no active session found";
        return;
    }

    QByteArray postData;
    QString param1 {"sessionId=" + mSessionId};

    postData.append(param1.toLocal8Bit());

    QNetworkRequest request(QUrl(config::apiUrl.toString() + config::endPoints["logout"]));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    mNetConnection.post(request, postData);

    resetUserRecord();
    mNetworkState = NetworkState::Logout;

    qDebug() << "Request to logout current user completed";
}

// TODO: Use a flag system that shows what state the user is in so you don't need to clear all the data
void UserSession::resetUserRecord()
{
    mUserRecord.username.clear();
    mUserRecord.firstName.clear();
    mUserRecord.lastName.clear();
    mUserRecord.password.clear();
    mUserRecord.emailAddress.clear();
    mUserRecord.sessionID.clear();
    mUserRecord.status = -1;
    mUserRecord.id = -1;
    mUserRecord.loggedIn = false;
}

void UserSession::handleNetworkResponse(QNetworkReply* reply)
{
    switch(mNetworkState)
    {
    case NetworkState::Login:
        loginResponse(reply);
        break;
    case NetworkState::Logout:
        logoutResponse(reply);
        break;
    default:
        qDebug() << "Invalid connection response received";
    }

    mNetworkState = NetworkState::NoConnection;
}

void UserSession::loginResponse(QNetworkReply* reply)
{
    //qDebug() << reply->readAll();

    QString rawJsonResponse {reply->readAll()};

    qDebug() << rawJsonResponse;

    QJsonDocument json;
    json = QJsonDocument::fromJson(rawJsonResponse.toUtf8());

    if(json.isNull())
    {
        emit loginProcessed(false);
        qDebug() << "Invalid Json received";
        return;
    }

    QJsonObject jsonObject = json.object();

    if(jsonObject["sessionID"].toString().isEmpty())
    {
        emit loginProcessed(false);
        qDebug() << "No session id found, failed to log in";
        return;
    }

    mUserRecord.loggedIn = true;
    mUserRecord.sessionID = jsonObject["sessionID"].toString();

    QString cookieName {"PHPSESSID"};
    QString cookieValue { mUserRecord.sessionID };
    QNetworkCookie cookie(cookieName.toLocal8Bit(), cookieValue.toLocal8Bit());
    cookie.setDomain(QString("ditalk.xyz"));
    mCookieJar.insertCookie(cookie);

    emit loginProcessed(true);
    qDebug() << "Login response received";
}

void UserSession::logoutResponse(QNetworkReply* reply)
{
    qDebug() << reply->readAll();

    resetUserRecord();

    qDebug() << "Logout response received";
}

bool UserSession::isLoggedIn()
{
    return mUserRecord.loggedIn;
}
