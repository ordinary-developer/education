import QtQuick 2.8
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true

    width: 640
    height: 480

    Rectangle {
        width: {
            var w = parent.width / 5;
            console.log("Current width: " + w);
            return w;
        }
        height: parent.height / 5

        anchors.centerIn: parent

        color: "gray"
    }
}
