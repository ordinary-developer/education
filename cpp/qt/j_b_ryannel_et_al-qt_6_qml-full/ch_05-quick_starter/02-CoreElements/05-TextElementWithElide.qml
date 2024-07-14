import QtQuick

Rectangle {
    width: 400
    height: 120

    Text {
        width: 40; height: 120
        text: 'A very long text'
        elide: Text.ElideMiddle
        style: Text.Sunken
        styleColor: '#FF4444'
        verticalAlignment: Text.AlignTop

        anchors.centerIn: parent
    }
}