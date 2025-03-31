import QtQuick 2.8

Rectangle {
    width: 300
    height: 150
    
    signal mousePositionChanged(int x, int y)
    
    onMousePositionChanged:
        txt.text = "<h1>X:" + x + "; Y:" + y + "</h1>"
        
    Text {
        id: txt
        text: "<h1>Move the Mouse</h1>"
        anchors.centerIn: parent
    }
    
    MouseArea {
        anchors.fill: parent
        hoverEnabled: true
        onMouseXChanged: parent.mousePositionChanged(mouseX, mouseY)
        onMouseYChanged: parent.mousePositionChanged(mouseX, mouseY)
    }
}
