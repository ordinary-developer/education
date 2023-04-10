import QtQuick
import QtQuick.Window

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Prj")

    Loader {
        anchors.centerIn: parent
        //sourceComponent: [c1, c2, c3][_.randFrom(0, 2)]
        sourceComponent: c3
    }

    Component {
        id: c1

        MyLabel {
            TextInput { text: "world1" }
        }
    }

    Component {
        id: c2

        MyLabel {
            someText: TextInput { text: "world2" }
        }
    }

    Component {
        id: c3

        MyLabel {
            TextInput { text: "will not be shown" }
            TextInput { text: "world3" }
        }
    }

    Item {
        id: _

        function randFrom(min, max) {
            return Math.floor(Math.random() * (max - min + 1)) + min
        }
    }

}
