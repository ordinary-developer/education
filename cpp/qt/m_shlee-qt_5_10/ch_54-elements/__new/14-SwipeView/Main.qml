import QtQuick 2.8
import QtQuick.Controls 2.2

Rectangle {
    width: 340
    height: 480

    SwipeView {
        id: sview
        currentIndex: 0
        width: parent.width
        height: parent.height - 20
        
        Repeater {
            id: repeater
            model: ["red", "green", "blue", "yellow", "black"]
            Label {
                x: 0
                y: 0
                color: "white"
                background: Rectangle { color: modelData }
                width: sview.width
                height: sview.height
                text: index
                style: Text.Sunken
                font.pixelSize: 256
                font.family: "Courier"
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignVCenter
            }
        }
    }
    
    PageIndicator {
        id: indicator
        count: sview.count
        currentIndex: sview.currentIndex
        
        x: parent.width / 2 - width / 2
        y: sview.height
    }
}