import QtQuick

Item {
    width: 200
    height: 120

    Rectangle {
        id: rect1
        x: 12; y: 12
        width: 76; height: 96
        color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
    }
    Rectangle {
        id: rect2
        x: 112; y: 12
        width: 76; height: 96
        border.color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
        border.width: 4
        radius: 8
    }
}
