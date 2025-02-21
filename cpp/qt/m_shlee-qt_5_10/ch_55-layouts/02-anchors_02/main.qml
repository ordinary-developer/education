import QtQuick 2.8
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
    width: 360
    height: 360

    Item {
        anchors.fill: parent

        Rectangle {
            anchors.fill: parent

            Text {
                text: "CenterIn"
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.verticalCenter: parent.verticalCenter
            }
        }
    }
}
