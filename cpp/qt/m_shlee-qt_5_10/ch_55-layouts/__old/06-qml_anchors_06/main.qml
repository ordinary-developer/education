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
        anchors.fill: parent 
    }
}
