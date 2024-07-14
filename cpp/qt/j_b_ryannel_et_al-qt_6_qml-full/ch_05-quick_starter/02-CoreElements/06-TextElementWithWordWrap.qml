import QtQuick

Rectangle {
    width: 400
    height: 120

    Text {
        width: 40; height: 120
        text: 'A very long text'
        style: Text.Sunken
        styleColor: '#FF4444'
        verticalAlignment: Text.AlignTop
        wrapMode: Text.WordWrap

        anchors.centerIn: parent
    }
}