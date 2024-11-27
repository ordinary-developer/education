import QtQuick 2.8
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
    width: 360
    height: 360

    Item {
        anchors.fill: parent

        Column {
            spacing: 2

            anchors.centerIn: parent

            Repeater {
                model: 10
                Rectangle {
                    width: 10
                    height: 10
                    color: "red"
                }
            }
        }
    }
}
