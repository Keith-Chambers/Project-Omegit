import QtQuick 2.0
import QtQuick.Controls 1.4

Item {

    anchors
    {
        top: parent.top
        left: parent.left
        right: parent.right
    }

    height: 50

    Rectangle
    {
        id: topBar
        anchors
        {
            fill: parent
        }
        color: "#F44336"

        Label
        {
            id: usernameLabel
            anchors
            {
                verticalCenter: parent.verticalCenter
                left: parent.left
                leftMargin: 50
            }
            font.pixelSize: 20
            font.bold: false
            text: "Logged in as: " + BackEnd.username;
        }

        Button
        {
            id: logoutButton
            anchors
            {
                verticalCenter: parent.verticalCenter
                right: parent.right
                rightMargin: 20
            }
            text: "Logout"
            onClicked:
            {
                if(BackEnd.waiting)
                    return;
                console.log("Clicked");
                BackEnd.logout();
            }
        }
    }
}
