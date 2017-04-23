#include "usersession.h"

UserSession::UserSession(QObject *parent) :
    QObject(parent), mNetConnection(), mNetworkState(NetworkState::NoConnection),
    mChatDetails(), mMessageThread(), mChatPollTimer()
{
    QObject::connect(&mNetConnection, SIGNAL(finished(QNetworkReply*)),
                     this, SLOT(handleNetworkResponse(QNetworkReply*)));

    QObject::connect(&mChatPollTimer, SIGNAL(timeout()), this, SLOT(updateMessageThread()));

    mChatPollTimer.setInterval(500);
    mChatPollTimer.setSingleShot(true);

    resetUserRecord();
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
    //qDebug() << reply->readAll();

    switch(mNetworkState)
    {
    case NetworkState::Login:
        loginResponse(reply);
        break;
    case NetworkState::Logout:
        logoutResponse(reply);
        break;
    case NetworkState::InitChat:
        startChatResponse(networkReplayToJsonObject(reply));
        break;
    case NetworkState::Connected:
        updateMessageThreadResponse(networkReplayToJsonArray(reply));
        break;
    default:
        qDebug() << "Invalid connection response received";
    }

    //mNetworkState = NetworkState::NoConnection;
}

void UserSession::loginResponse(QNetworkReply* reply)
{
    QString rawJsonResponse {reply->readAll()};

    //qDebug() << "Raw Json: " + rawJsonResponse;

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

void UserSession::startChatResponse(QJsonObject &pJsonObject)
{
    qDebug() << "Response to starting chat received";

    if(pJsonObject["chatId"].toString().isEmpty())
    {
        qDebug() << "Failed to obtain chat id";
        qDebug() << pJsonObject["errorMessage"].toString();
        return;
    }

    mChatDetails.setChatId(pJsonObject["chatId"].toString());
    mChatDetails.setPartnerId(pJsonObject["partnerId"].toString());
    mChatDetails.partnerUsername = pJsonObject["partnerUsername"].toString();

    qDebug() << "Chat started with id :" << mChatDetails.chatId;

    if(mChatDetails.chatId == NULL)
    {
        qDebug() << "ChatId is NULL";
        return;
    }else
    {
        qDebug() << "Chat Id is not null";
    }

    mNetworkState = NetworkState::Connected;

    qDebug() << "Updating message thread";
    updateMessageThread();

}

void UserSession::updateMessageThread(QString pMessage)
{
    mChatPollTimer.stop();

    QByteArray postData;
    QString param1 {"chatId=" + QString(mChatDetails.chatId) + "&"};
    QString param2 {"lastMessageId=" + QString(mMessageThread.getLastMessageId()) + "&"};
    QString param3 {"newMessage=" + pMessage };

    postData.append(param1.toLocal8Bit());
    postData.append(param2.toLocal8Bit());
    postData.append(param3.toLocal8Bit());

    QNetworkRequest request(QUrl(config::apiUrl.toString() + config::endPoints["chat"]));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    mNetConnection.post(request, postData);

    mNetworkState = NetworkState::Connected;

    qDebug() << "Request to update chat sent";
}

void UserSession::updateMessageThread()
{
    QByteArray postData;
    QString param1 {"chatId=" + QString(mChatDetails.chatId) + "&"};
    QString param2 {"lastMessageId=" + QString(mMessageThread.getLastMessageId()) };

    postData.append(param1.toLocal8Bit());
    postData.append(param2.toLocal8Bit());

    QNetworkRequest request(QUrl(config::apiUrl.toString() + config::endPoints["chat"]));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    mNetConnection.post(request, postData);
    mNetworkState = NetworkState::Connected;

    qDebug() << "Request to update chat sent";
}

void UserSession::updateMessageThreadResponse(QJsonArray pJsonArray)
{
    for(int i = 0; i < pJsonArray.size(); i++)
    {
        QJsonObject jsonObject = pJsonArray.at(i).toObject();
        qDebug() << jsonObject["senderId"].toString() + ": " + jsonObject["content"].toString();

        QString content = jsonObject["content"].toString();
        int senderId = jsonObject["senderId"].toInt();
        QString senderUsername;
        QColor color;
        int messageId = jsonObject["id"].toInt();

        if(senderId == mChatDetails.partnerId)
        {
            color = QColor(200, 100, 50);
            senderUsername = mChatDetails.partnerUsername;
        }
        else
        {
            senderUsername = "You";
            color = QColor(50, 100, 200);
        }

        Message newMessage(content, senderUsername, color, messageId);
        qDebug() << "Added message with ID: " << QString(messageId);

        if(messageId == NULL)
        {
            qDebug() << "Message ID is null";
            return;
        }else
        {
            qDebug() << "Not null!";
        }
        mMessageThread.addItem(newMessage);
    }

    mChatPollTimer.stop();
    mChatPollTimer.start();

    qDebug() << "Chat Poll Timer set for " + QString(mChatPollTimer.remainingTime());

    return;
}

void UserSession::startChat()
{
    QByteArray postData;

    QNetworkRequest request(QUrl(config::apiUrl.toString() + config::endPoints["usersConnect"]));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    mNetConnection.post(request, postData);
    mNetworkState = NetworkState::InitChat;

    qDebug() << "Request to start chat sent";
}

MessageThread *UserSession::getMessageThread()
{
    return &mMessageThread;
}

QJsonObject UserSession::networkReplayToJsonObject(QNetworkReply* reply)
{
    QString output {reply->readAll()};
    qDebug() << output;
    QJsonDocument json;
    json = QJsonDocument::fromJson(output.toUtf8());

    if(json.isNull() || !json.isObject())
    {
        qDebug() << "Failed to create json object";
        return QJsonObject();
    }

    return json.object();
}

QJsonArray UserSession::networkReplayToJsonArray(QNetworkReply* reply)
{
    QString output {reply->readAll()};
    qDebug() << output;
    QJsonDocument json;
    json = QJsonDocument::fromJson(output.toUtf8());

    if(json.isNull() || !json.isArray())
    {
        qDebug() << "Failed to create json array";
        return QJsonArray();
    }

    return json.array();
}














