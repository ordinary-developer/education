import QtQuick 2.8
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
    width: 150
    height: 100

    Item {
        anchors.fill: parent

        MyTextField {
            x: 10
            y: 20
            color: "yellow"
            text: "Text Text Text<br>Text Text Text"
            border.width: 1
        }
    }
}
