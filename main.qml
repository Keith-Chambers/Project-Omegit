import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import DitalkEnums 1.0

ApplicationWindow {
    visible: true
    width: BackEnd.appWidth
    height: BackEnd.appHeight

    /* minimumHeight: height
    minimumWidth: width
    maximumHeight: height
    maximumWidth: width */

    property int loggedIn: AppState.LoggedIn
    property int loggedOut: AppState.LoggedOut
    property int chatting: AppState.Chatting

    title: qsTr("DiTalk")

    StateGroup
    {
        id: myStateGroup

        states:[

            State
            {
                name: "login"
                PropertyChanges{ target: loginPage; visible: true; }
                when: bar.currentIndex === 0 && BackEnd.state === AppState.LoggedOut
            },

            State
            {
                name: "register"
                PropertyChanges{ target: registerPage; visible: true; }
                when: bar.currentIndex === 1 && BackEnd.state === AppState.LoggedOut
            },

            State
            {
                name: "loggedIn"
                PropertyChanges{ target: startChatPage; visible: true; }
                PropertyChanges{ target: bar; visible: false; }
                when: BackEnd.state === AppState.LoggedIn
            },

            State
            {
                name: "chatting"
                PropertyChanges {target: messageThread; visible: true; }
                PropertyChanges {target: messageInputControl; visible: true}
                PropertyChanges{ target: bar; visible: false; }
                when: BackEnd.state === AppState.Chatting
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

    MessageInputControl
    {
        id: messageInputControl
        visible: false
        anchors
        {
            top: messageThread.bottom
            left: messageThread.left
        }
    }
}
