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

            x: 0
            y: 0
            width: parent.width / 2
            height: parent.height / 2

            color: "red"
        }

        Rectangle {
            x: redrect.width
            y: redrect.height
            width: redrect.width
            height: redrect.height

            color: "green"
        }
    }
}
