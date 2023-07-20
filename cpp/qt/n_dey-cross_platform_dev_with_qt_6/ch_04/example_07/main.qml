import QtQuick
import QtQuick.Window


Window {
    width: 640; height: 480
    visible: true
    title: qsTr("QML CPP integration")

    Text {
        anchors.centerIn: parent
        text: "C++ Context Property Value: " + radius
    }
}
