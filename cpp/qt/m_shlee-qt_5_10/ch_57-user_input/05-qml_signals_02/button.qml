import QtQuick 2.8
BorderImage {
    property alias text: txt.text
    signal clicked
    
    source: "qrc:/button.png"
    width: txt.width + 15
    height: txt.height + 15
    border { left: 15; top: 12; right: 15; bottom: 12 }
    
    Text {
        id: txt
        color: "white"
        anchors.centerIn: parent
    }
    
    MouseArea {
        anchors.fill: parent
        onClicked: parent.clicked()
        onPressed: parent.source = "qrc:/button_pressed.png"
        onReleased: parent.source = "qrc:/button.png"
    }
}
