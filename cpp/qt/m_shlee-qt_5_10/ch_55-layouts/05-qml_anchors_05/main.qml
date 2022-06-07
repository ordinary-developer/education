import QtQuick 2.8

Rectangle {
    width: 360
    height: 360
    
    Rectangle {
        color: "lightgreen"
        anchors.fill: text
    }
    
    Text {
        id: text
        text: "Text"
        anchors {
            left: parent.left
            right: parent.right
            top: parent.top
            bottom: parent.bottom
        }
    }
}
