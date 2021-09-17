import QtQuick 2.8

Item {
    width: 360
    height: 360
    
    Rectangle {
        color: "red"
        anchors {
            right: parent.horizontalCenter
            left: parent.left
            top: parent.top
            bottom: parent.bottom
            leftMargin: 5
            topMargin: 5
            rightMargin: 5
            bottomMargin: 5
        }
    }
    
    Rectangle {
        color: "green"
        anchors {
            left: parent.horizontalCenter
            right: parent.right
            top: parent.top
            bottom: parent.bottom
            leftMargin: 20
            topMargin: 20
            rightMargin: 20
            bottomMargin: 20
        }
    }
}
