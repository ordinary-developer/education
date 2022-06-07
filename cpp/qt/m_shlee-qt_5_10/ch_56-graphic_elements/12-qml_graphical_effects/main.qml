import QtQuick 2.8
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0

Column {
    FastBlur {
        id: blur
        Image {
            id: sourceImage
            visible: false
            source: "qrc:/image.jpg"
        }
        
        width: sourceImage.width
        height: sourceImage.height
        source: sourceImage
    }
    
    Slider {
        id: sld
        width: sourceImage.width
        value: 0
        from: 0
        to: 64
        stepSize: 1
        onValueChanged: {
            blur.radius = value
        }
    }
}
