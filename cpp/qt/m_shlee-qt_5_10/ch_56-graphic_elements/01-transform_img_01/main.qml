import QtQuick 2.8

Rectangle {
    color: "aqua"
    width: img.width
    height: img.height
    
    Image {
        id: img
        x: 0
        y: 0
        smooth: true
        source: "qrc:/image.jpg"
        scale: 0.75
        rotation: -30.0
    }
}