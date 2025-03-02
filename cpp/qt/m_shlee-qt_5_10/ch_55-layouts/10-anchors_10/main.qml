import QtQuick 2.8
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
    width: 360
    height: 360

    Item {
        anchors.fill: parent

        Rectangle {
            id: redrect
            color: "red"
            width: parent.width / 1.5
            height: parent.height / 1.5
            anchors.top: parent.top
            anchors.left: parent.left
        }

        Rectangle {
            opacity: 0.5
            color: "green"
            anchors.top: redrect.verticalCenter
            anchors.bottom: parent.bottom
            anchors.left: redrect.horizontalCenter
            anchors.right: parent.right
        }
   }
}
