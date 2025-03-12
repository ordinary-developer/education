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
            width: 50
            height: 50
            anchors {
                verticalCenterOffset: 10
                verticalCenter: parent.verticalCenter
                horizontalCenterOffset: 10
                horizontalCenter: parent.horizontalCenter
            }
        }
    }
}
