import QtQuick 2.4

Item
{
    id: rootItem
    width: pWidth
    height: pHeight

    // Defaults
    property int pWidth: 150
    property int pFontSize: 15
    property int pMaxLength: 20
    property color pBackgroundColour: "white"
    property color pBorderColour: "black"
    property string pPlaceholderText: "Placeholder"
    property bool pEnablePasswordEcho: false

    // Alias'
    property alias rWidth: rootItem.pWidth;
    property alias fontSize: rootItem.pFontSize
    property alias maxLength: rootItem.pMaxLength
    property alias backgroundColor: rootItem.pBackgroundColour
    property alias borderColor: rootItem.pBorderColour
    property alias placeHolderText: rootItem.pPlaceholderText
    property alias enablePasswordEcho: rootItem.pEnablePasswordEcho
    property alias text: textInput.text

    // Private
    property int pHeight: pFontSize + 8;
    property int pTopPadding: (pHeight - pFontSize)/2;
    property int pTextInputX: 2;
    property int pTextInputY: pTopPadding;
    property int pTextInputWidth: pWidth - (pTextInputY * 2);
    property int pTextInputHeight: pFontSize;
    property int pBorderWidth: 1

    Rectangle {
        id: root
        x: 0
        y: 0
        width: pWidth
        height: pHeight
        color: pBackgroundColour
        border.color: pBorderColour;
        border.width: pBorderWidth

        TextInput {
            id: textInput
            x: pTextInputX
            y: pTextInputY
            width: pTextInputWidth
            height: pFontSize + 2
            opacity: 1
            selectionColor: "#f5f2ef"
            font.family: "Tahoma"
            font.weight: Font.Light
            cursorVisible: false
            font.pixelSize: pFontSize
            maximumLength: pMaxLength
            echoMode: (pEnablePasswordEcho) ? TextInput.Password : TextInput.Normal;

            Text {
                id: placeholderText
                text: qsTr(pPlaceholderText)
                font.weight: Font.Light
                font.family: "Tahoma"
                color: "grey"
                font.pixelSize: pFontSize
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter

                anchors
                {
                    fill: parent
                }
            }
        }
    }

    Connections {
        target: textInput
        onFocusChanged: {
            placeholderText.text = (textInput.focus || textInput.text != "") ? "" : pPlaceholderText;
            textInput.cursorVisible = (textInput.focus || textInput.text != "") ? true : false;
        }
    }
}
