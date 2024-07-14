import QtQuick

Rectangle {
    width: 400; height: 100
    
    color: '#333333'
    
    Image {
        x: 12; y: 12
        source: "assets/triangle_red.png"
    }
    Image {
        x: 12 + 64 + 12; y: 12
        height: 72 / 2
        source: "assets/triangle_red.png"
        fillMode: Image.PreserveAspectCrop
        clip: true
    }
}
