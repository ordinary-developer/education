import QtQuick

BrightSquare {
    id: root

    width: 160
    height: 160

    Flow {
        spacing: 20
        
        anchors.margins: 20
        anchors.fill: parent
        
        RedSquare {}
        BlueSquare {}
        GreenSquare {}
    }
}
