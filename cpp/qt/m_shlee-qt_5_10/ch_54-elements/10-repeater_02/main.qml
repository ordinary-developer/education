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
                model: ["one", "two", "three", "four", "five"]
                Rectangle {
                    border.width: 1
                    border.color: "red"

                    width: txt.width + 5
                    height: txt.height + 5

                    Text {
                        id: txt
                        text: modelData
                        anchors.centerIn: parent
                    }
                }
            }
        }
    }
}
