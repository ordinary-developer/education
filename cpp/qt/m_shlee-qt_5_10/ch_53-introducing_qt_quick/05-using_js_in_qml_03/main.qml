import QtQuick 2.8
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true

    width: 640
    height: 480

    Rectangle {
        function maximum(a, b) {
            return a > b ? a : b;
        }

        width: maximum(parent.width / 5, 100)
        height: parent.height / 5

        anchors.centerIn: parent

        color: "gray"
    }
}
