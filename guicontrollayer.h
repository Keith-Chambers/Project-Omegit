#ifndef GUICONTROLLAYER_H
#define GUICONTROLLAYER_H

#include <QObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QByteArray>

#include "ditalkregistration.h"
#include "usersession.h"
#include "messagethread.h"

/*
 * 'Throwaway layer' for interactions between QML and C++ backend
 */

class GuiControlLayer : public QObject
{
    Q_OBJECT

    typedef struct FrontEndState
    {
        int applicationHeight = 400;
        int applicationWidth = 350;
    } FrontEndState;

    Q_PROPERTY(bool loggedIn READ isLoggedIn WRITE setLoggedIn NOTIFY loggedInChanged)
    Q_PROPERTY(int appHeight READ getAppHeight WRITE setAppHeight NOTIFY appHeightChanged)
    Q_PROPERTY(int appWidth READ getAppWidth WRITE setAppWidth NOTIFY appWidthChanged)
    Q_PROPERTY(bool chatting READ isChatting WRITE setChatting NOTIFY chattingChanged)

public:
    explicit GuiControlLayer(QJsonDocument pClientInfo, QObject *parent = 0);
    Q_INVOKABLE bool registerUser(QString pUsername, QString pPassword,
                                  QString pEmailPrefix, QString pEmailSuffix);
    Q_INVOKABLE bool loginUser(QString pUsername, QString pPassword);
    Q_INVOKABLE void startChat();
    bool isLoggedIn();
    void setLoggedIn(bool isLoggedIn){ Q_UNUSED(isLoggedIn); qDebug() << "Set loggedin called"; }
    int getAppWidth();
    void setAppWidth(int pWidth){ Q_UNUSED(pWidth); }
    int getAppHeight();
    void setAppHeight(int pHeight){ Q_UNUSED(pHeight); }
    bool isChatting() { return mUserSession.isChatting(); }
    void setChatting(bool val) { Q_UNUSED(val); }

    MessageThread *getMessageThread();
private slots:
    void relayLoggedIn(bool pIsLoggedIn);
    void changeApplicationDimensions(bool pIsLoggedIn);
signals:
    void loggedInChanged(bool);
    void appHeightChanged();
    void appWidthChanged();
    void chattingChanged();
private:
    QJsonDocument mClientInfo;
    UserSession mUserSession;
    FrontEndState mFrontEndState;
};

#endif // GUICONTROLLAYER_H
