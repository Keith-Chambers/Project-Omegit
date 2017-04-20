import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

ApplicationWindow {
    visible: true
    width: 350
    height: 400
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
                PropertyChanges{ target: dummyMainPage; visible: true; }
                PropertyChanges{ target: bar; visible: false; }
                when: BackEnd.loggedIn === true
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

    DummyMainPage
    {
        id: dummyMainPage
        visible: false
    }
}
