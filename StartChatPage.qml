import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    anchors.fill: parent

    Button
    {
        height: 50
        width: 200
        text: "Start Chat"
        anchors.centerIn: parent

        onClicked:
        {
            console.log("Button clicked");
            BackEnd.startChat();
        }
    }
}
