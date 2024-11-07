import QtQuick 2.8
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
    width: 360
    height: 360

    Item {
        anchors.fill: parent

        Rectangle {
            color: "darkkhaki"
            x: 100
            y: 50
            width: 170
            height: 200
            border.color: "black"
            border.width: 10
            radius: 40
            smooth: true
        }
    }
}
