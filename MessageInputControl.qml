import QtQuick 2.0
import QtQuick.Controls 1.4

Item {
    width: 300
    height: 60

    signal textEntered

    TextArea
    {
        id: messageTextBox
        anchors.fill: parent
        anchors.rightMargin: 40
    }

    Rectangle
    {
        id: messageInputButton
        color: "light blue"

        anchors.left: messageTextBox.right
        anchors.right: parent.right
        anchors.top: parent.top
        anchors.bottom: parent.bottom

        Text
        {
            anchors.centerIn: parent
            text: "Enter"
        }

        MouseArea
        {
            anchors.fill: parent
            hoverEnabled: true

            onHoveredChanged: messageInputButton.color = (!containsMouse) ? "light blue" : "grey";
            onClicked:
            {
                if(messageTextBox.text != "")
                {
                    BackEnd.sendMessage(messageTextBox.text);
                    textEntered();
                    messageTextBox.text = "";
                }
            }
        }
    }
}
