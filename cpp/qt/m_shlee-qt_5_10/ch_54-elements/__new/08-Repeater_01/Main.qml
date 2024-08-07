import QtQuick 2.8

Item {
    width: 360
    height: 360

    Column {
        spacing: 2
        
        anchors.centerIn: parent

        Repeater {
            model: 10
            Rectangle {
                width: 10
                height: 10
                color: "red"
            }
        }
    }
}
