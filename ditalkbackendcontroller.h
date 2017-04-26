#ifndef DITALKBACKENDCONTROLLER_H
#define DITALKBACKENDCONTROLLER_H

#include <QObject>
#include <QString>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QNetworkAccessManager>
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QDesktopServices>
#include <QUrl>
#include <QCryptographicHash>
#include <QNetworkCookieJar>
#include <QNetworkCookie>
#include <QJsonArray>

#include "chatmanager.h"
#include "util.h"
#include "ditalkstate.h"

typedef struct RegistrationDetails
{
    QString username;
    QString password;
    QString emailPrefix;
    QString emailSuffix;
} RegistrationDetails;

typedef struct UserRecord
{
    QString username;
    QString firstName;
    QString lastName;
    QString sessionID;
} UserRecord;

class DitalkBackendController : public QObject
{
    Q_OBJECT
public:
    explicit DitalkBackendController(QQmlApplicationEngine *pEngine, QObject *parent = 0);
    bool login(QString username, QString password);
    void logout();
    void registerAccount(RegistrationDetails pRegistrationDetails);
    DitalkState::State getState();
    bool sendMessage(QString pMessage);
    //void stopChat();
    bool newChat();
    QString getUsername();
    QString getFirstName();
    QString getLastName();
    QString getFullName();

signals:
    void newIncomingMessage(QString pMessage);
    void stateChanged(DitalkState::State pNewState);
    void usernameChanged();
    void firstNameChanged();
    void lastNameChanged();
    void fullNameChanged();
    void startChatFailed();
public slots:
    void onNewChat();
    void onChatDisconnected();
    void loginResponse(QNetworkReply* reply);
    void logoutResponse(QNetworkReply* reply);
private:
    QQmlApplicationEngine *mEngine;
    QNetworkAccessManager mNetConnection;
    ChatManager mChatManager;
    UserRecord mUserRecord;
    DitalkState::State mState;
    QNetworkCookieJar mCookieJar;
};

#endif // DITALKBACKENDCONTROLLER_H
