#ifndef MessageThread_H
#define MessageThread_H

#include <QObject>
#include <QAbstractListModel>
#include <QList>
#include <QVariant>
#include <QDebug>
#include <QColor>
#include <QDate>

typedef struct Message
{
    QString body;
    QString senderUsername;
    QColor color;
    int messageId;

    Message(QString pBody, QString pSenderUsername, QColor pColor, int pMessageId) :
        body(pBody), senderUsername(pSenderUsername), color(pColor), messageId(pMessageId){}
} Message;

class MessageThread : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit MessageThread(QObject *parent = 0);

    enum ModelRoles {
        SenderUsernameRole = Qt::UserRole + 1,
        ColorRole,
        BodyRole,
        MessageIdRole
    };

    void addItem(const Message &item);
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    int getLastMessageId();
    //bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);

signals:
public slots:
protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<Message> mMessageList;
};

#endif // MessageThread_H
