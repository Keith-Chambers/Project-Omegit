#ifndef GUICONTROLLAYER_H
#define GUICONTROLLAYER_H

#include <QObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QByteArray>

#include "ditalkregistration.h"
#include "usersession.h"

class GuiControlLayer : public QObject
{
    Q_OBJECT

    Q_PROPERTY(bool loggedIn READ isLoggedIn WRITE setLoggedIn NOTIFY loggedInChanged)

public:
    explicit GuiControlLayer(QJsonDocument pClientInfo, QObject *parent = 0);
    Q_INVOKABLE bool registerUser(QString pUsername, QString pPassword,
                                  QString pEmailPrefix, QString pEmailSuffix);
    Q_INVOKABLE bool loginUser(QString pUsername, QString pPassword);
    bool isLoggedIn();
    void setLoggedIn(bool isLoggedIn){ Q_UNUSED(isLoggedIn); qDebug() << "Set loggedin called"; }
private slots:
    void relayLoggedIn(bool pIsLoggedIn);
signals:
    void loggedInChanged(bool);
private:
    QJsonDocument mClientInfo;
    UserSession mUserSession;
};

#endif // GUICONTROLLAYER_H
