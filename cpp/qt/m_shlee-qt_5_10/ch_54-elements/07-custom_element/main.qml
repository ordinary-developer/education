import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 150
    height: 100

    Item {
        anchors.fill: parent

        TextField {
            x: 10
            y: 20
            color: "yellow"
            text: "Text Text Text<br>Text Text Text"
            border.width: 1
        }
    }
}
