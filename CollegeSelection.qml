import QtQuick 2.0
import QtQuick.Controls 1.4

Item
{
    id: root
    width: pWidth;
    height: combo.height

    // Defaults
    property int pWidth: 120

    // Alias'
    property alias rWidth: root.pWidth;
    property alias text: combo.currentText;

    ComboBox
    {
        id: combo
        width: pWidth
        // TODO: Make a model from this that gets the
        // actual list from the DB
        model: ["@mydit.ie [DIT]"]
    }
}
