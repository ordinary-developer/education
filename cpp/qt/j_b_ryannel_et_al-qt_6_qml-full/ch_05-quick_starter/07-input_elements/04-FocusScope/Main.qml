import QtQuick

Rectangle {
    width: 200
    height: 80
    color: "linen"

    TLineEditV2 {
        id: input1
        x: 8; y: 8
        focus: true
        text: "Text Input 1"
        KeyNavigation.tab: input2
    }

    TLineEditV2 {
        id: input2
        x: 8; y: 36
        text: "Text Input 2"
        KeyNavigation.tab: input1
    }
}
