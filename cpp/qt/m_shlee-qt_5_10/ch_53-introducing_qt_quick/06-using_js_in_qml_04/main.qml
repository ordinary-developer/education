import QtQuick 2.8
import QtQuick.Controls 2.2

import "myfunctions.js" as MyScripts

ApplicationWindow {
    visible: true
    width: 640
    height: 480

    Rectangle {
        width: MyScripts.maximum(parent.width / 5, 100)
        height: parent.height / 5

        anchors.centerIn: parent

        color: "gray"
    }
}
