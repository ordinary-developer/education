import QtQuick

DarkSquare {
    id: root
    width: 400; height: 240
    
    BlueSquare {
        id: blue
        x: 24; y: 24
   
        MouseArea {
            anchors.fill: parent
            drag.target: parent
            onClicked: parent.x = 24
        }
    }
    
    RedSquare {
        id: red
        
        anchors.left: blue.right
        anchors.leftMargin: 8
        anchors.right: root.right
        anchors.rightMargin: 8
        anchors.top: blue.bottom
        anchors.topMargin: 8
        
        MouseArea {
            anchors.fill: parent
            onClicked: {
                print("set x to 24")
                parent.x = 24
            }
        }
    }
}