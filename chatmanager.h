#ifndef CHATMANAGER_H
#define CHATMANAGER_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QByteArray>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QDebug>
#include <QTimer>
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

#include "config.h"
#include "messagethread.h"

class ChatManager : public QObject
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
    explicit ChatManager(QQmlApplicationEngine *pEngine, QNetworkAccessManager &pConnection,
                         QObject *parent = 0);
    /*  Sends a request to the server to start a new chat
     */
    void startChat();
signals:
    /*  Emitted when updateMessageThreadResponse(QJsonArray pJsonArray) is
     *  passed new messages in it's argument pJsonArray
     */
    void newIncomingMessage(QString pMessage);
    /*  Emitted when a valid response is obtained from startChat() request that
     *  indicates that a chat connection was successfully established
     */
    void newChatEstablished();
    /*  Emitted when chat connection is disconnected
     */
    void chatDisconnected();
public slots:
    void startChatResponse(QNetworkReply *pReply);
    /*
     * Sends the user's message to the server
     * The server will process the message and return all new message information,
     * including the message that was sent as a parameter
     * Network response is handled by updateMessageThreadResponse(QJsonArray pJsonArray)
     */
    void newOutgoingMessage(QString pMessage);
    /*
     * Handles the servers response to request sent by startChat)
     */

    /*
     * Gets new message data from the server and updates MessageThread model
     */
    void updateMessageThreadResponse(QNetworkReply * pReply);
    /*
     * Sends a polling request to the server to check for message updates
     * Respnse is handled by updateMessageThreadResponse(QJsonArray pJsonArray)
     */
    void updateMessageThread();

private:
    /*  Sends a polling request to the server to get new messages between client and other
     *  message partner
     */
    void updateMessageThreadResponse();
    QJsonObject networkReplayToJsonObject(QNetworkReply* reply);
    QJsonArray networkReplayToJsonArray(QNetworkReply* reply);

    QQmlApplicationEngine *mEngine;
    QNetworkAccessManager &mNetConnection;
    QTimer mChatPollTimer;
    ChatDetails mChatDetails;
    MessageThread mMessageThread;
};

#endif // CHATMANAGER_H
