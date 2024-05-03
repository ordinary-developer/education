import QtQuick

BrightSquare {
    id: root
    
    width: row.childrenRect.width + 2 * margins
    height: row.childrenRect.height + 2 * margins
    
    property int margins: 20
    
    Row {
        id: row
        
        anchors.fill: parent
        anchors.margins: parent.margins
        
        spacing: root.margins / 2
        
        RedSquare {}
        RedSquare {}
        RedSquare {}
    }
}
