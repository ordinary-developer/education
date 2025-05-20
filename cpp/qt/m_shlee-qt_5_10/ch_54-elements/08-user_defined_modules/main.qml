import QtQuick 2.8
import QtQuick.Controls 2.2

// for the last version
import "UserDefinedModule"

// for the specified version
//import "UserDefinedModule" 1.1

ApplicationWindow {
    visible: true
    width: 150
    height: 100

    Item {
        anchors.fill: parent
        
        TextField {
            x: 10
            y: 20
            text: "Text Text Text<br>Text Text Text"
            border.width: 1
        }
    }
}
