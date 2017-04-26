import QtQuick 2.0
import QtQuick.Controls 2.1
import QtQuick.Controls 1.4

Item {
    width: 400
    height: 400

    Rectangle
    {
        id: displayRoot
        anchors.fill: parent
        color: "white"
        border.width: 1
        border.color: "black"

        ScrollView
        {
            id: threadScrollBar
            anchors.fill: parent
            anchors.margins: 2

            ListView
            {
                id: messageListView
                width: parent.width;
                height: parent.height
                interactive: false
                spacing: 0
                clip: true

                model: MessageThreadModel
                delegate:
                    MessageElement
                    {
                        backgroundColor: messageColor
                        width: parent.width
                        username: senderUsername
                        messageBody: body
                    }
            }
        }
    }
}
