import QtQuick 2.8
import QtQuick.Layouts 1.3

Item {
    width: 360
    height: 160
    
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
