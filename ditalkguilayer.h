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
public:
    explicit DitalkGuiLayer(DitalkBackendController &pBackend, QObject *parent = 0);
    Q_INVOKABLE void login(QString pUsername, QString pPassword);
    Q_INVOKABLE void registerUser(QString pUsername, QString pPassword,
                                  QString pEmailPrefix, QString pEmailSuffix);
    Q_INVOKABLE void startChat();
    Q_INVOKABLE int getAppWidth();
    Q_INVOKABLE int getAppHeight();
    Q_INVOKABLE void sendMessage(QString pMessage);
    Q_INVOKABLE DitalkState::State getState();
signals:
    void stateChanged(DitalkState::State pNewState);
    void appHeightChanged();
    void appWidthChanged();
public slots:
    void onStateChanged(DitalkState::State pNewState);
private:
    FrontEndState mFrontEndState;
    DitalkBackendController &mBackend;
};

#endif // DITALKGUILAYER_H
