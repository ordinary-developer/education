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
            anchors.left: parent.left
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: 60
        }

        Rectangle {
            color: "yellow"
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            anchors.left: redrect.right
            anchors.right: greenrect.left
        }

        Rectangle {
            id: greenrect
            color: "green"
            anchors.right: parent.right
            anchors.top: parent.top
            anchors.bottom: parent.bottom
            width: 100
        }
    }
}
