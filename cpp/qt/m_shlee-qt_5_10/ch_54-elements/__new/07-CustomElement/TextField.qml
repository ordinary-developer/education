import QtQuick 2.8

Rectangle {
    property alias text: txt.text
    
    Text {
        id: txt
        x: 0
        y: 0
    }
}