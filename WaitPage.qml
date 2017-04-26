import QtQuick 2.0
import QtQuick.Controls 1.4


// TODO: Make this more reuseable
// TODO: Rename to waitOverlay
Item
{
    width: 350
    height: 390

    Rectangle
    {
        id: displayRoot
        color: "grey";
        opacity: .5

        anchors
        {
            fill: parent
        }

        BusyIndicator
        {
            running: true
            anchors.centerIn: parent
            height: 100
            width: 100
        }
    }
}
