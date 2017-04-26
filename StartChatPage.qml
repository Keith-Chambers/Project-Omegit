import QtQuick 2.0
import QtQuick.Controls 1.4
import QtQuick.Controls.Material 2.1

Item {
    anchors.fill: parent
    Material.theme: Material.Light
    Material.accent: Material.Red

    Rectangle
    {
        id: displayRoot
        anchors.fill: parent
        color: "#E6E6E6";

        Button
        {
            id: startChatButton
            height: 50
            width: 200
            text: "Start Chat"
            anchors.centerIn: parent

            Material.theme: Material.Light
            Material.accent: Material.Red

            onClicked:
            {
                if(BackEnd.waiting)
                    return;
                console.log("Button clicked");
                BackEnd.startChat();
            }
        }

        TopBar
        {
            id: topBar
            anchors.top: parent.top;
            anchors.left: parent.left
            anchors.right: parent.right
            height: 50
        }

        Rectangle
        {
            id: welcomeMessageRect
            anchors
            {
                top: topBar.bottom
                topMargin: 30
                left: parent.left
                right: parent.right
                leftMargin: 30
                rightMargin: 30
            }

            border.width: 2
            border.color: "black"
            radius: 2
            height: welcomeMessageText.height

            Label
            {
                id: welcomeMessageText
                anchors.fill: parent
                text: "Welcome " + BackEnd.firstName + ", click 'Start Chat' to start a new random conversation";
                font.pixelSize: 20
                wrapMode: Text.WordWrap
            }
        }

        WaitPage
        {
            id: waitPage
            anchors.fill: parent
            visible: BackEnd.waiting
        }
    }
}
