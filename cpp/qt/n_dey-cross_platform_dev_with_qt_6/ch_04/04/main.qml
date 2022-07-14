import QtQuick
import QtQuick.Window

Window {
    width: 500; height: 200
    visible: true
    title: qsTr("Positioner Demo")

    Row {
        id: row

        Rectangle {
            id: yellowRect
            width: 150; height: 100
            color: "yellow"
            border.color: "black"
        }

        Rectangle {
            id: redRect
            width: 150; height: 100
            color: "red"
            border.color: "black"
        }

        Rectangle {
            id: greenRect
            width: 150; height: 100
            color: "green"
            border.color: "black"
        }
    }
}
