#ifndef USERSESSION_H
#define USERSESSION_H

#include <QString>
#include <QUrl>
#include <QNetworkCookieJar>
#include <QNetworkAccessManager>
#include <QHash>
#include <QMetaObject>
#include <QNetworkRequest>
#include <QObject>
#include <QNetworkReply>
#include <QCryptographicHash>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QNetworkCookie>
#include <QTimer>

#include "config.h"
#include "messagethread.h"

enum class NetworkState { NoConnection, Login, Logout, InitChat, Connected, Size };

typedef struct UserRecord
{
    QString username;
    QString firstName;
    QString lastName;
    QString password;
    QString emailAddress;
    QString sessionID;
    int status;
    int id;
    bool loggedIn;
} UserRecord;

class UserSession : public QObject
{
    Q_OBJECT

    typedef struct ChatDetails
    {
        int chatId;
        QString partnerUsername;
        int partnerId;

        ChatDetails() : partnerUsername()
        {chatId = -1; partnerId = -1;}

        void clear()
        {
            chatId = -1;
            partnerId = -1;
            partnerUsername = "";
        }

        void setChatId(QString pString)
        {
            chatId = pString.toInt();
        }

        void setPartnerId(QString pString)
        {
            partnerId = pString.toInt();
        }

    } ChatDetails;

public:
    UserSession(QObject *parent = 0);
    bool login(QString username, QString password);
    void logout();
    bool isLoggedIn();
    void startChat();
    MessageThread *getMessageThread();
    void updateMessageThread(QString pMessage);
    bool isChatting(){ if(mNetworkState == NetworkState::Connected) return true; else return false; }
private slots:
    void handleNetworkResponse(QNetworkReply* reply);
    void updateMessageThread();
signals:
    void loginProcessed(bool);
private:
    void resetUserRecord();
    void loginResponse(QNetworkReply* reply);
    void logoutResponse(QNetworkReply* reply);
    void startChatResponse(QJsonObject &pJsonObject);
    void updateMessageThreadResponse(QJsonArray pJsonArray);
    void updateMessageThreadResponse();
    QJsonObject networkReplayToJsonObject(QNetworkReply* reply);
    QJsonArray networkReplayToJsonArray(QNetworkReply* reply);

    QString mSessionId;
    QNetworkCookieJar mCookieJar;
    QNetworkAccessManager mNetConnection;
    UserRecord mUserRecord;
    NetworkState mNetworkState;
    MessageThread mMessageThread;
    ChatDetails mChatDetails;
    QTimer mChatPollTimer;
};

#endif // USERSESSION_H
