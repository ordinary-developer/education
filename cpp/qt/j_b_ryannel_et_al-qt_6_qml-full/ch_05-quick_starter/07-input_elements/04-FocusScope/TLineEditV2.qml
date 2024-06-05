import QtQuick

FocusScope {
    width: 96; height: input.height + 8

    Rectangle {
        anchors.fill: parent
        color: "lightsteelblue"
        border.color: "gray"
    }

    property alias text: input.text
    property alias input: input

    TextInput {
        id: input
        anchors.fill: parent
        anchors.margins: 4 // comment to make a correct placement into the parent component
        focus: true
    }
}
