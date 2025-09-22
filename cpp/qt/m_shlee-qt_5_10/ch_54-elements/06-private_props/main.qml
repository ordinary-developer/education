import QtQuick 2.8
import QtQuick.Controls 2.2

ApplicationWindow {
    visible: true

    width: 360
    height: 360

    Item {
        anchors.fill: parent

        Rectangle {
            color: "darkkhaki"

            QtObject {
                id: priv
                readonly property int nX: 23
                readonly property int nY: 50
            }

            x: priv.nX
            y: priv.nY

            width: 170
            height: 200
        }
    }
}
