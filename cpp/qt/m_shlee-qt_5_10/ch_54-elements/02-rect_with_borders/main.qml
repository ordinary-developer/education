import QtQuick 2.8
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true

    width: 360
    height: 360

    Item {
        anchors.fill: parent

        Rectangle {
            x: 100
            y: 50

            width: 170
            height: 200

            border.color: "black"
            border.width: 10

            smooth: true
            radius: 40
            color: "darkkhaki"
        }
    }
}
