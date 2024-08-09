import QtQuick 2.8
import QtQuick.Layouts 1.3

Item {
    width: 320
    height: 240
    
    ColumnLayout {
        anchors.fill: parent
        anchors.margins: 10
        
        spacing: 10
        Rectangle {
            Layout.fillWidth: true
            Layout.minimumWidth: 64;
            Layout.minimumHeight: 64;
            color: "red"
        }
        Rectangle {
            Layout.fillHeight: true
            Layout.minimumWidth: 64;
            Layout.minimumHeight: 64;
            color: "blue"
        }
        Rectangle {
            Layout.fillWidth: true
            Layout.minimumWidth: 64;
            Layout.minimumHeight: 64;
            color: "green"
        }
    }
}
