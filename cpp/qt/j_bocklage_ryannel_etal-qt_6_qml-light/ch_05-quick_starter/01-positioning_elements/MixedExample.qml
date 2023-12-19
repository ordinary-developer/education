import QtQuick

Column {
    width: 240
    height: 120
    
    GreenSquare {
        height: parent.height * 0.2; width: parent.width
    }
    
    Row {
        height: parent.height * 0.6; width: parent.width
        
        BlueSquare { width: parent.width * 0.4; height: parent.height }
        BlueSquare { width: parent.width * 0.6; height: parent.height }
    }
    
    GreenSquare {
        height: parent.height * 0.2; width: parent.width
    }
}
