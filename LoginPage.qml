import QtQuick 2.4
import QtQuick.Controls 2.1

Item {
    width: 350
    height: 390

    Rectangle {
        id: displayRoot
        x: 0
        y: 0
        width: 350
        height: 390
        color: "#E6E6E6"

        KTextInput
        {
            id: usernameInput
            x: 75
            y: 150
            pFontSize: 25
            pWidth: 200
            pPlaceholderText: "Username"
        }

        Button {
            id: button
            x: 109
            y: 300
            width: 133
            height: 32
            text: qsTr("login")

            onClicked:
            {
                BackEnd.login(usernameInput.text, passwordInput.text);
                usernameInput.text = "";
                passwordInput.text = "";
            }
        }

        Rectangle
        {
            y: 15
            height: 100
            width: 300
            color: "#E6E6E6"

            anchors
            {
                left: parent.left;
                right: parent.right
                leftMargin: 50
                rightMargin: 50
            }

            Text {
                id: text1
                anchors.fill: parent
                text: qsTr("\"Some sort of uplifting quote mayhaps\"<br/> - Some Guy")
                font.family: "Arial"
                wrapMode: Text.WordWrap
                font.pixelSize: 20
                verticalAlignment: Text.AlignVCenter
            }
        }

        KTextInput {
            id: passwordInput
            x: 75
            y: 220
            pFontSize: 25
            pEnablePasswordEcho: true
            pWidth: 200
            pPlaceholderText: "Password"
        }

    }

    WaitPage
    {
        id: waitPageId
        visible: false
    }
}
