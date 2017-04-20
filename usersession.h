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
#include <QNetworkCookie>

#include "config.h"

enum class NetworkState { NoConnection, Login, Logout, Size };

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

public:
    UserSession(QObject *parent = 0);
    bool login(QString username, QString password);
    void logout();
    bool isLoggedIn();
private slots:
    void handleNetworkResponse(QNetworkReply* reply);
signals:
    void loginProcessed(bool);
private:
    void resetUserRecord();
    void loginResponse(QNetworkReply* reply);
    void logoutResponse(QNetworkReply* reply);

    QString mSessionId;
    QNetworkCookieJar mCookieJar;
    QNetworkAccessManager mNetConnection;
    UserRecord mUserRecord;
    NetworkState mNetworkState;
};

#endif // USERSESSION_H
