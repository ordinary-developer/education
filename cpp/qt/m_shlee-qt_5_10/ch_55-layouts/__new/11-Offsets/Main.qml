import QtQuick 2.8

Item {
    width: 360
    height: 180

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
