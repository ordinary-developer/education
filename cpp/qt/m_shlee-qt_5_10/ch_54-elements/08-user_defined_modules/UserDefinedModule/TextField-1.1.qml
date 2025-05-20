import QtQuick 2.8

Rectangle {
    property alias text: txt.text
    property string name: "TextField"
    
    width: txt.width
    height: txt.height
    
    color: "red"
    
    Text {
        id: txt
        x: 0
        y: 0
    }
}
