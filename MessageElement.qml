import QtQuick 2.0

Item {

    property string username: "Unknown User"
    property string messageBody: "Default"
    property color backgroundColor: "light blue"
    property int messageWidth: 100

    width: messageWidth;
    height: displayRoot.height

    Rectangle
    {
        id: displayRoot
        color: backgroundColor
        width: parent.width
        height: bodyText.height + 20
        radius: 20

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
