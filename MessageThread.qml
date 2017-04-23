import QtQuick 2.0
import QtQuick.Controls 2.1

Item {
    width: 300
    height: 400

    Rectangle
    {
        anchors.fill: parent

        color: "white"
        border.width: 1
        border.color: "black"

        MouseArea
        {
            anchors.fill: parent

            onClicked:
            {
                console.log("HTins");
            }
        }

        ListView {
            id: messageListView
            width: parent.width;
            height: parent.height
            interactive: false
            spacing: 5
            clip: true

            model: Model
            delegate:
                MessageElement
                {
                    backgroundColor: messageColor
                    messageWidth: parent.width - 20
                    username: senderUsername
                    messageBody: body
                }

            ScrollBar
            {
               id: messageScrollBar
               hoverEnabled: true
               active: hovered || pressed
               orientation: Qt.Vertical
               size: 0.15
               anchors.top: parent.top
               anchors.right: parent.right
               anchors.bottom: parent.bottom

               onPositionChanged: messageListView.contentY = -(position * messageListView.height);
           }
        }
    }
}
