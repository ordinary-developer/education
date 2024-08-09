import QtQuick 2.8

Item {
    width: 360
    height: 160
    
    Row {
        anchors.centerIn: parent
        spacing: 10

        Rectangle {
            width: 64; height: 64; color: "red"
        }
 
        Rectangle {
            width: 64; height: 64; color: "blue"
        }
 
        Rectangle {
            width: 64; height: 64; color: "green"
        }
    }
}
