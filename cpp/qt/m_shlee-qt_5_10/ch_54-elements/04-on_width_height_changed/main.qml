import QtQuick 2.8
import QtQuick.Window 2.2

Window {
    visible: true
    width: 200
    height: 200

    Item {
        anchors.fill: parent

        Rectangle {
            width: parent.width
            height: parent.height
            onWidthChanged: {
                console.log("width changed: " + width);
            }
            onHeightChanged: {
                console.log("height changed: " + height);
            }
        }
    }
}
