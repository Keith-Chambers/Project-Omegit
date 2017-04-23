import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: BackEnd.appWidth
    height: BackEnd.appHeight
    /*
    minimumHeight: BackEnd.appHeight
    minimumWidth: BackEnd.appWidth
    maximumHeight: BackEnd.appHeight
    maximumWidth: BackEnd.appWidth
    */

    title: qsTr("DiTalk")

    StateGroup
    {
        id: myStateGroup

        states:[

            State
            {
                name: "login"
                PropertyChanges{ target: loginPage; visible: true; }
                when: bar.currentIndex === 0 && !BackEnd.loggedIn
            },

            State
            {
                name: "register"
                PropertyChanges{ target: registerPage; visible: true; }
                when: bar.currentIndex === 1 && !BackEnd.loggedIn
            },

            State
            {
                name: "loggedIn"
                PropertyChanges{ target: startChatPage; visible: true; }
                PropertyChanges{ target: bar; visible: false; }
                when: BackEnd.loggedIn === true
            },

            State
            {
                name: "chatting"
                PropertyChanges {target: messageThread; visible: true; }
                PropertyChanges{ target: bar; visible: false; }
                when: BackEnd.chatting === true
            }

        ]
    }

    header: TabBar
    {
        id: bar
        width: parent.width
        height: 40

        TabButton {
            text: qsTr("Login")
        }
        TabButton {
            text: qsTr("Register")
        }
    }

    RegisterPage
    {
        id: registerPage
        visible: false
    }

    LoginPage
    {
        id: loginPage
        visible: false
    }

    StartChatPage
    {
        id: startChatPage
        visible: false
    }

    MessageThread
    {
        id: messageThread
        visible: false
    }
}
