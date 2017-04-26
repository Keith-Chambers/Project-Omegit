#ifndef DITALKSTATE_H
#define DITALKSTATE_H

#include <QObject>
#include <QQmlEngine>
#include <QDebug>
#include <QtQml>

class DitalkState : public QObject
{
    Q_OBJECT

    public:
        enum State { LoggedOut, LoggedIn, Chatting, Size};
        Q_ENUMS(State)

        // Do not forget to declare your class to the QML system.
        static void declareQML() {
            qmlRegisterType<DitalkState>("DitalkEnums", 1, 0, "AppState");
        }
};

#endif // DITALKSTATE_H
