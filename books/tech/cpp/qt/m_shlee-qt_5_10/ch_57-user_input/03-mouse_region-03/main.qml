import QtQuick 2.8

Rectangle {
    width: 200
    height: 200
    color: "lightgreen"
    
    Text {
        text: "<h1>Hover Me!</h1>"
        anchors.centerIn: parent
    }
    
    MouseArea {
        id: mousearea
        anchors.fill: parent
        hoverEnabled: true
        onEntered: parent.color = "red"
        onExited: parent.color = "lightgreen"
    }
}
