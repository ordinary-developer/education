import QtQuick 2.8
import QtQuick.Controls 2.2

Rectangle {
    color: "aqua"
    width: 320
    height: 240
    
    Image {
        id: img
        anchors.fill: parent
        smooth: true
        source: "http://qt-book.com/pic.jpg"
        Column {
            anchors.centerIn: parent
            visible: img.status == Image.Loading ? true : false
            Text {
                text: "Loading..."
            }
            BusyIndicator {}
        }
    }
}
