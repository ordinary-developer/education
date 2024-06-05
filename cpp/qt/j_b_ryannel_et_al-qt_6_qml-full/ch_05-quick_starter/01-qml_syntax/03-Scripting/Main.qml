import QtQuick

Rectangle {
    width: 240
    height: 120

    Text {
        id: label

        x: 24; y: 24

        property int spacePresses: 0

        text: "Space pressed: " + spacePresses + " times"

        onTextChanged: function(text) {
            console.log("text changed to:", text)
        }

        focus: true

        Keys.onSpacePressed: {
            increment()
        }

        Keys.onEscapePressed: {
            label.text = ''
        }

        function increment() {
            spacePresses = spacePresses + 1
        }
    }
}
