import QtQuick 2.8
BorderImage {
    property alias text: txt.text
	property bool clicked
    
    source: "qrc:/button.png"
    width: txt.width + 15
    height: txt.height + 15
    border { left: 15; top: 12; right: 15; bottom: 12 }
    
    Text {
        id: txt
        color: "white"
        anchors.centerIn: parent
    }
    
    MouseArea {
        anchors.fill: parent
        onPressed: {
        	parent.source = "qrc:/button_pressed.png"
        	parent.clicked = false
        }
        onReleased: {
        	parent.source = "qrc:/button.png"
        	parent.clicked = true
        }
    }
}
