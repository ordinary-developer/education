import QtQuick 2.8

Rectangle {
    width: txt.width + 20
    height: txt.height + 20
    color: "lightgreen"
    Text {
        id: txt
        anchors.centerIn: parent
        text: "<h1>Click Me!<br>(use left or right mouse button)</h1>"
        horizontalAlignment: Text.AlignHCenter
    }
    
    MouseArea {
        anchors.fill: parent
        acceptedButtons: Qt.LeftButton | Qt.RightButton
        onPressed: {
            if (mouse.button == Qt.RightButton) {
                parent.color = "red"
            }
            else {
                parent.color = "blue"
            }
        }
        onReleased: parent.color = "lightgreen"
    }
}
