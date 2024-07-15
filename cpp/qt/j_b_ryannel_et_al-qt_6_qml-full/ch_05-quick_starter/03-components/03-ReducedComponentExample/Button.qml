import QtQuick

Item {
    id: root
    width: 116; height: 26

    property alias text: label.text
    signal clicked
    
    Rectangle {
        anchors.fill: parent
        color: "lightsteelblue"
        border.color: "slategray"
    }

    Text {
        id: label
        anchors.centerIn: parent
        text: "Start"
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            root.clicked()
        }
    }
}
