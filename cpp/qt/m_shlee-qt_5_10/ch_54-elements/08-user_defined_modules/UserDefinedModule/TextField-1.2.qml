import QtQuick 2.8

Rectangle {
    property alias text: txt.text
    property string name: "TextField"

    color: "green"

    width: txt.width
    height: txt.height

    Text {
        id: txt
        x: 0
        y: 0
    }
}
