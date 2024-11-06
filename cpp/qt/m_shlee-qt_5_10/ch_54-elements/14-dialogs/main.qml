import QtQuick 2.8
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.2

ApplicationWindow {
    width: 200
    height: 150
    visible: true
    title: "Dialogs Demo"

    Repeater {
        id: repeater
        model: [colorDialog, fontDialog, fileDialog]
        Button {
            y: index * (parent.height / repeater.count)
            height: parent.height / repeater.count
            text: modelData.title
            onClicked: {
                messageDialog.visible = false;
                modelData.visible = true;
            }
        }
    }

    ColorDialog {
        id: colorDialog
        visible: false
        modality: Qt.WindowModal
        title: "Select color"
        color: "blue"
        onAccepted: {
            messageDialog.informativeText = "Selected color: " + color;
            messageDialog.visible = true;
        }
    }

    FontDialog {
        id: fontDialog
        visible: false
        modality: Qt.WindowModal
        title: "Select font"
        onAccepted: {
            messageDialog.informativeText = "Selected font: " + font
            messageDialog.visible = true
        }
    }

    FileDialog {
        id: fileDialog
        visible: false
        modality: Qt.WindowModal
        title: "Select file"
        nameFilters: [ "Doc (*.txt *.html)", "All fiels (*)" ]
        onAccepted: {
            messageDialog.informativeText = "Selected files: " + fileUrls;
            messageDialog.visible = true;
        }
    }

    MessageDialog {
        id: messageDialog
        visible: false
        modality: Qt.NonModal
        title: "Message"
    }
}
