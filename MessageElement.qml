import QtQuick 2.0

Item {

    property string username: "Unknown User"
    property string messageBody: "Default"
    property color backgroundColor: "light blue"

    height: messageBodyRect.height + messageHeader.height

    Rectangle
    {
        id: messageHeader
        anchors
        {
            top: parent.top
            left: parent.left
            right: parent.right
        }

        height: 20
        color: backgroundColor

        Text
        {
            anchors
            {
                left: parent.left
                leftMargin: 5
                verticalCenter: parent.verticalCenter
            }

            text: senderUsername
        }
    }

    Rectangle
    {
        id: messageBodyRect
        height: bodyText.height + 20
        anchors
        {
            top: messageHeader.bottom
            right: parent.right
            left: parent.left
        }
        color: backgroundColor

        Text
        {
            id: bodyText

            anchors
            {
                left: parent.left
                right: parent.right
                top: parent.top

                leftMargin: 15
                rightMargin: 15
                topMargin: 10
            }

            font.pointSize: 10
            text: messageBody
            wrapMode: Text.WordWrap
        }
    }
}
