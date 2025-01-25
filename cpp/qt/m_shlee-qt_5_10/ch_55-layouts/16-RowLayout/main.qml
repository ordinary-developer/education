import QtQuick 2.8
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 360
    height: 360

    Item {
        anchors.fill: parent

        Item {
            anchors.fill: parent

            RowLayout {
                anchors.fill: parent
                anchors.margins: 10
                spacing: 10

                Rectangle {
                    Layout.fillHeight: true
                    Layout.minimumWidth: 64
                    Layout.minimumHeight: 64
                    color: "red"
                }

                Rectangle {
                    Layout.fillWidth: true
                    Layout.minimumWidth: 64
                    Layout.minimumHeight: 64
                    color: "blue"
                }

                Rectangle {
                    Layout.fillHeight: true
                    Layout.minimumWidth: 64
                    Layout.minimumHeight: 64
                    color: "green"
                }
            }
        }
    }
}
