import QtQuick 2.8
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true
    width: 360
    height: 360
    
    Item {
        anchors.fill: parent

        Rectangle {
            color: "red"
            anchors {
                verticalCenterOffset: 10
                verticalCenter: parent.verticalCenter

                right: parent.horizontalCenter
                left: parent.left
                top: parent.top
                bottom: parent.bottom
                leftMargin: 5
                rightMargin: 5
            }
        }

        Rectangle {
            color: "green"
            anchors {
                verticalCenterOffset: -10
                verticalCenter: parent.verticalCenter
                
                left: parent.horizontalCenter
                right: parent.right
                top: parent.top
                bottom: parent.bottom
                leftMargin: 20
                rightMargin: 20
            }
        }
    }
}
