import QtQuick

DarkSquare {
    id: root

    width: 252
    height: 252

    property variant colorArray: ["#00bbe3", "#67c111", "#ea7025"]

    Grid {
        spacing: 4

        anchors.margins: 8
        anchors.fill: parent

        Repeater {
            model: 16
 
            delegate: Rectangle {
                required property int index
                property int colorIndex: Math.floor(Math.random() * 3)

                width: 55
                height: 56
                color: root.colorArray[colorIndex]
                border.color: Qt.lighter(color)

                Text {
                    anchors.centerIn: parent

                    color: "#f0f0f0"
                    text: "Cell " + parent.index
                }
            }
        }
    }
}
