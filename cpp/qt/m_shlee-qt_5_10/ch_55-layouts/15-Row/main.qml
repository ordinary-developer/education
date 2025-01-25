import QtQuick 2.8
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
    width: 360
    height: 360

    Item {
        anchors.fill: parent

        Item {
            anchors.fill: parent

            Row {
                anchors.centerIn: parent
                spacing: 10

                Rectangle { width: 64; height: 64; color: "red" }
                Rectangle { width: 64; height: 64; color: "blue" }
                Rectangle { width: 64; height: 64; color: "green" }
            }
        }
    }
}
