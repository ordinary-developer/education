import QtQuick
import QtQuick.Window

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Multitouch Example")

    Item {
        anchors.fill: parent

        TapHandler {
            acceptedButtons: Qt.LeftButton
            onTapped: console.log("Left Button Clicked!")
        }

        TapHandler {
            acceptedButtons: Qt.MiddleButton
            onTapped: console.log("Middle Button clicked!")
        }

        TapHandler {
            acceptedButtons: Qt.RightButton
            onTapped: console.log("Right Button Clicked!")
        }

        TapHandler {
            acceptedDevices: PointerDevice.Stylus
            onTapped: console.log("Stylus Tap!")
        }
    }
}
