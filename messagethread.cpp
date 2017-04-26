#include "MessageThread.h"

MessageThread::MessageThread(QObject *parent) : QAbstractListModel(parent)
{

}

Qt::ItemFlags MessageThread::flags(const QModelIndex &index) const
{
    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable;
}

void MessageThread::addItem(const Message &pMessage)
{
    /* If pMessage sender is the same as the last message sent,
     * just append the message contents of pMessage to the last message
     */
    if(mMessageList.size() > 0 && mMessageList.back().senderUsername == pMessage.senderUsername)
    {
        QString messageContent = pMessage.body;
        messageContent.prepend(QChar('\n'));
        mMessageList.back().body.append(messageContent);
        mMessageList.back().messageId = pMessage.messageId;
        dataChanged(QAbstractListModel::index(mMessageList.size() - 1), QAbstractListModel::index(mMessageList.size() - 1));
        return;
    }

    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    mMessageList.append(pMessage);
    endInsertRows();
}

int MessageThread::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mMessageList.count();
}

QVariant MessageThread::data(const QModelIndex &index, int role) const
{
    qDebug() << "Getting data from model";

    if(index.row() < 0 || index.row() >= mMessageList.count())
        return QVariant();

    const Message &message = mMessageList[index.row()];

    switch(role)
    {
    case SenderUsernameRole:
        return message.senderUsername;
    case ColorRole:
        return message.color;
    case BodyRole:
        return message.body;
    case MessageIdRole:
        return message.messageId;
    default:
        return QVariant();
    }
}

enum ModelRoles {
    SenderUsernameRole = Qt::UserRole + 1,
    ColorRole,
    BodyRole,
    MessageIdRole
};

QHash<int, QByteArray> MessageThread::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[SenderUsernameRole] = "senderUsername";
    roles[ColorRole] = "messageColor";
    roles[BodyRole] = "body";
    roles[MessageIdRole] = "messageId";

    return roles;
}

int MessageThread::getLastMessageId()
{
    return (mMessageList.size() > 0) ? mMessageList.last().messageId : -1;
}
