#ifndef DITALKGUILAYER_H
#define DITALKGUILAYER_H

#include <QObject>

#include "ditalkstate.h"
#include "ditalkbackendcontroller.h"

typedef struct FrontEndState
{
    int applicationHeight = 400;
    int applicationWidth = 350;
} FrontEndState;

class DitalkGuiLayer : public QObject
{
    Q_OBJECT

    Q_PROPERTY(DitalkState::State state READ getState NOTIFY stateChanged)
    Q_PROPERTY(int appHeight READ getAppHeight NOTIFY appHeightChanged)
    Q_PROPERTY(int appWidth READ getAppWidth NOTIFY appWidthChanged)
    Q_PROPERTY(QString username READ getUsername NOTIFY usernameChanged)
    Q_PROPERTY(QString firstName READ getFirstName NOTIFY firstNameChanged)
    Q_PROPERTY(QString lastName READ getLastName NOTIFY lastNameChanged)
    Q_PROPERTY(QString fullName READ getFullName NOTIFY fullNameChanged)
    Q_PROPERTY(bool waiting READ getWaiting NOTIFY waitingChanged)

public:
    explicit DitalkGuiLayer(DitalkBackendController &pBackend, QObject *parent = 0);
    Q_INVOKABLE void login(QString pUsername, QString pPassword);
    Q_INVOKABLE void registerUser(QString pUsername, QString pPassword,
                                  QString pEmailPrefix, QString pEmailSuffix);
    Q_INVOKABLE void startChat();
    Q_INVOKABLE void logout();
    Q_INVOKABLE int getAppWidth();
    Q_INVOKABLE int getAppHeight();
    Q_INVOKABLE void sendMessage(QString pMessage);
    Q_INVOKABLE DitalkState::State getState();

    Q_INVOKABLE QString getUsername();
    Q_INVOKABLE QString getFirstName();
    Q_INVOKABLE QString getLastName();
    Q_INVOKABLE QString getFullName();
    Q_INVOKABLE bool getWaiting();
signals:
    void stateChanged(DitalkState::State pNewState);
    void appHeightChanged();
    void appWidthChanged();
    void usernameChanged();
    void firstNameChanged();
    void lastNameChanged();
    void fullNameChanged();
    void waitingChanged(bool);
public slots:
    void onStartChatFailed();
    void onStateChanged(DitalkState::State pNewState);
private:
    FrontEndState mFrontEndState;
    DitalkBackendController &mBackend;
    bool mWaiting = false;
};

#endif // DITALKGUILAYER_H
