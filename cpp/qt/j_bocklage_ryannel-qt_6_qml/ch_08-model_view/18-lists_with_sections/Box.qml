import QtQuick

Rectangle {
    id: root

    property alias text: label.text
    property color fontColor: '#1f1f1f'

    width: 64
    height: 64

    color: "#ffffff"
    border.color: Qt.darker(color, 1.2)

    Text {
        id: label
        anchors.centerIn: parent
        font.pixelSize: 14
        color: root.fontColor
    }
}
