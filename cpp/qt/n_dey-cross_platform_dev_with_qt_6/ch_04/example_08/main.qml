import QtQuick
import backend.element

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    UsingElements {
        id: backendElement
    }

    Text {
        anchors.centerIn: parent
        text: "From Backend Element : " + backendElement.readValue()
    }
}
