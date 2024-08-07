import QtQuick 2.8
Item {
    width: 200
    height: 200
    Rectangle {
        width: parent.width
        height: parent.height
        onWidthChanged: {
            console.log("width changed: " + width)
        }
        onHeightChanged: {
            console.log("height changed: " + height)    
        }
    }
}