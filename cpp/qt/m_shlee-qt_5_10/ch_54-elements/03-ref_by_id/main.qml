import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 360
    height: 360
    
    Item {
        anchors.fill: parent

        Rectangle {
            id: redrect
            color: "red"
            x: 0
            y: 0
            width: parent.width / 2
            height: parent.height / 2
        }

        Rectangle {
            color: "green"
            x: redrect.width
            y: redrect.height
            width: redrect.width
            height: redrect.height
        }
    }
}