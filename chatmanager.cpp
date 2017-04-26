#include "chatmanager.h"

ChatManager::ChatManager(QQmlApplicationEngine *pEngine, QNetworkAccessManager &pConnection, QObject *parent) :
    mNetConnection(pConnection), mChatPollTimer(this), mChatDetails(), mMessageThread(this), QObject(parent)
{
    mEngine = pEngine;
    mEngine->rootContext()->setContextProperty("MessageThreadModel", &mMessageThread);

    QObject::connect(&mChatPollTimer, SIGNAL(timeout()), this, SLOT(updateMessageThread()));

    mChatPollTimer.setInterval(config::chatPollFreqMilliSecs);
    mChatPollTimer.setSingleShot(true);
}

void ChatManager::startChat()
{
    QByteArray postData;

    QNetworkRequest request(QUrl(config::apiUrl.toString() + config::endPoints["usersConnect"]));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    mNetConnection.disconnect();
    QObject::connect(&mNetConnection, &QNetworkAccessManager::finished,
                     this, &ChatManager::startChatResponse);

    mNetConnection.post(request, postData);

    qDebug() << "Request to start chat sent";
}

void ChatManager::updateMessageThread()
{
    QByteArray postData;
    QString param1 {"chatId=" + QString::number(mChatDetails.chatId) + "&"};
    QString param2 {"lastMessageId=" + QString::number(mMessageThread.getLastMessageId()) };

    qDebug() << "Updaing message thread";
    qDebug() << "ChatId: " + QString::number(mChatDetails.chatId);
    qDebug() << "Last Message Id: " + QString::number(mMessageThread.getLastMessageId());

    postData.append(param1.toLocal8Bit());
    postData.append(param2.toLocal8Bit());

    QNetworkRequest request(QUrl(config::apiUrl.toString() + config::endPoints["chat"]));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    mNetConnection.disconnect();
    QObject::connect(&mNetConnection, SIGNAL(finished(QNetworkReply*)),
                     this, SLOT(updateMessageThreadResponse(QNetworkReply *)));
    mNetConnection.post(request, postData);

    qDebug() << "Request to update chat sent";
}

void ChatManager::updateMessageThreadResponse(QNetworkReply * pReply)
{
    //qDebug() << "Message thread response received";

    QJsonArray jsonArray(networkReplayToJsonArray(pReply));

    qDebug() << "New Messages: " << jsonArray.size();
    qDebug() << "Partner Id:" << mChatDetails.partnerId;

    for(int i = 0; i < jsonArray.size(); i++)
    {
        QJsonObject jsonObject = jsonArray.at(i).toObject();
        qDebug() << jsonObject["senderId"].toString() + ": " + jsonObject["content"].toString();

        QString content = jsonObject["content"].toString();
        int senderId = QString(jsonObject["senderId"].toString()).toInt();
        QString senderUsername;
        QColor color;

        int messageId = QString(jsonObject["id"].toString()).toInt();

        if(senderId == mChatDetails.partnerId)
        {
            color = QColor(0,188,212);
            senderUsername = mChatDetails.partnerUsername;
        } else
        {
            senderUsername = "You";
            color = QColor(96,125,139);
        }

        Message newMessage(content, senderUsername, color, messageId);
        qDebug() << "Added message with ID: " << QString::number(messageId);

        mMessageThread.addItem(newMessage);
        emit newIncomingMessage(content);
    }

    mChatPollTimer.stop();
    mChatPollTimer.start();

    //qDebug() << "Chat Poll Timer set for " + QString(mChatPollTimer.remainingTime());
}

QJsonObject ChatManager::networkReplayToJsonObject(QNetworkReply* reply)
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

QJsonArray ChatManager::networkReplayToJsonArray(QNetworkReply* reply)
{
    QString output {reply->readAll()};
    QString sep("\n end");
    qDebug() << output;
    output = output.section(sep, 0, 0);
    QJsonDocument json;
    json = QJsonDocument::fromJson(output.toUtf8());

    if(json.isNull() || !json.isArray())
    {
        qDebug() << "Failed to create json array";
        return QJsonArray();
    }

    return json.array();
}

void ChatManager::startChatResponse(QNetworkReply *pReply)
{
    qDebug() << "Response to starting chat received";
    QJsonObject jsonObject(networkReplayToJsonObject(pReply));

    if(jsonObject["chatId"].toString().isEmpty())
    {
        qDebug() << "Failed to obtain chat id";
        qDebug() << jsonObject["errorMessage"].toString();
        emit startChatTimeOut();
        return;
    }

    mChatDetails.setChatId(jsonObject["chatId"].toString());
    mChatDetails.setPartnerId(jsonObject["partnerId"].toString());
    mChatDetails.partnerUsername = jsonObject["partnerUsername"].toString();

    qDebug() << "Chat started with id :" << mChatDetails.chatId;

    qDebug() << "Updating message thread";
    emit newChatEstablished();
    updateMessageThread();
}

void ChatManager::newOutgoingMessage(QString pMessage)
{
    mChatPollTimer.stop();
    qDebug() << "Sending out a new message!";
    qDebug() << "Chat Id: " + QString::number(mChatDetails.chatId);
    qDebug() << "Last Message Id: " + QString::number(mMessageThread.getLastMessageId());
    qDebug() << "New Message: " + pMessage;

    QByteArray postData;
    QString param1 {"chatId=" + QString::number(mChatDetails.chatId) + "&"};
    QString param2 {"lastMessageId=" + QString::number(mMessageThread.getLastMessageId()) + "&"};
    QString param3 {"newMessage=" + pMessage };

    postData.append(param1.toLocal8Bit());
    postData.append(param2.toLocal8Bit());
    postData.append(param3.toLocal8Bit());

    QNetworkRequest request(QUrl(config::apiUrl.toString() + config::endPoints["chat"]));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");

    mNetConnection.disconnect();
    QObject::connect(&mNetConnection, SIGNAL(finished(QNetworkReply*)),
                     this, SLOT(updateMessageThreadResponse(QNetworkReply *)));

    mNetConnection.post(request, postData);
    mChatPollTimer.start();

    qDebug() << "Request to update chat sent";
}
