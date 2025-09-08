import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true

    title: qsTr("Hello World")

    width: 640
    height: 480

    MouseArea {
        anchors.fill: parent
        onClicked: {
            console.log(qsTr("Clicked on background. Text: '" + textEdit.text + "'"));
        }
    }

    TextEdit {
        id: textEdit

        anchors.top: parent.top
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.topMargin: 20

        verticalAlignment: Text.AlignVCenter

        text: qsTr("Enter some text...")

        Rectangle {
            anchors.fill: parent
            anchors.margins: -10

            border.width: 1

            color: "transparent"
        }
    }
}
