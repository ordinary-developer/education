import QtQuick
import QtQuick.Window

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    Rectangle {
        x: 50
        y: 50
        width: 100; height: 80
        color: "blue"
    }
}
