import QtQuick 2.8
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
    width: 360
    height: 360

    Item {
        anchors.fill: parent

        Rectangle {
            anchors.fill: parent

            Rectangle {
                color: "lightgreen"
                anchors.fill: text
            }

            Text {
                id: text
                text: "Text"
                anchors {
                    left: parent.left
                    right: parent.right
                    top: parent.top
                    bottom: parent.bottom
                }
            }
        }
    }
}
