import QtQuick 2.8

Rectangle {
    width: sourceImage.width
    height: sourceImage.height
    color: "Black"
    ShaderEffect {
        Image {
            id: sourceImage
            width: sourceWidth
            height: sourceHeight
            visible: false
            source: "qrc:/image.jpg"
        }
        
        width: sourceImage.width
        height: sourceImage.height
        
        property variant source: sourceImage
        fragmentShader: "
            uniform sampler2D source;
            uniform lowp float qt_Opacity;
            varying highp vec2 qt_TexCoord0;
            void main() {
                gl_FragColor = 
                    abs(texture2D(source, qt_TexCoord0) * qt_Opacity - 1.0);
            }"
    }
}
