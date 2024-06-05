import QtQuick

Column {
    width: 240
    height: 120

    GreenSquare {
        width: parent.width
        height: parent.height * 0.2
    }

    Row {
        width: parent.width
        height: parent.height * 0.6

        BlueSquare { width: parent.width * 0.4; height: parent.height }
        BlueSquare { width: parent.width * 0.6; height: parent.height }
    }

    GreenSquare {
        width: parent.width
        height: parent.height * 0.2
    }
}
