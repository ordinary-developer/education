import QtQuick 2.8
import QtQuick.Controls 2.2

ApplicationWindow {
    width: buttons.width
    height: buttons.height
    visible: true
    title: "Buttons"

    Column {
        id: buttons

        CheckBox { text: "Check Box" }
        DelayButton { text: "Radio Button" }
        RadioButton { text: "Radio Button 1" }
        RadioButton { text: "Radio Button 2" }
        RoundButton { text: "Round Button " }
        Switch { text: "Switch" }
        ToolButton { text: "Tool Button" }
        Button { text: "Quit"; onClicked: Qt.quit() }
    }
}
