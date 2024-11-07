import QtQuick 2.8
import QtQuick.Controls 2.2

ApplicationWindow {
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
