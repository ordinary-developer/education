import QtQuick

Text {
    default property var someText

    text: "Hello, " + someText.text
}
