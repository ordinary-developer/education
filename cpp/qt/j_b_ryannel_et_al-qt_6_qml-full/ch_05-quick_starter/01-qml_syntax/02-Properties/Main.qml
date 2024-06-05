import QtQuick

Rectangle {
    width: 240
    height: 120

    Text {
        id: thisLabel

        x: 24; y: 16

        height: 2 * width

        property int times: 24

        property alias anotherTimes: thisLabel.times

        text: "Greetings " + times

        font.family: "Ubuntu"
        font.pixelSize: 24

        KeyNavigation.tab: otherLabel
        
        onHeightChanged: console.log('height:', height)

        focus: true

        color: focus ? "red" : "black"
    }
    
    Text {
        id: otherLabel
        x: 24
        y: 64
        text: "Other Label"

        font.family: "Ubuntu"
        font.pixelSize: 24

        KeyNavigation.tab: thisLabel
        color: focus ? "red" : "black"
    }
}
