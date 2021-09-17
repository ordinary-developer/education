import QtQuick 2.8
import QtQuick.Layouts 1.3

Item {
    width: 480
    height: 200
    
    Flow {
        anchors.fill: parent
        anchors.margins: 20
        spacing: 20
        Repeater {
            model: {
                var v = new Array(10);
                for (var i = 0; i < v.length; ++i) {
                    v[i] = i % 2 ? "green" : "red"
                }
                return v;
            }
            
            Rectangle {
                width: 64
                height: 64
                radius: 32
                color: modelData
                Text {
                    color: "white"
                    font.pixelSize: 48
                    font.family: "Courier"
                    anchors.centerIn: parent
                    text: index
                }
            }
        }
    }
}
