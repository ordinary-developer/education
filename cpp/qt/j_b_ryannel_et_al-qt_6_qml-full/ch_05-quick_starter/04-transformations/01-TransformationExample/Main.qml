import QtQuick

Item {
    width: bg.width
    height: bg.height

    Image {
        id: bg
        source: "assets/background.png"
    }

    MouseArea {
        id: backgroundClicker
        anchors.fill: parent
        onClicked: {
            circle.x = 84
            box.rotation = 0
            triangle.rotation = 0
            triangle.scale = 1.0
        }
    }

    ClickableImage {
        id: circle
        x: 84; y: 68
        source: "assets/circle_blue.png"
        antialiasing: false
        onClicked: {
            x += 20
        }
    }

    ClickableImage {
        id: box
        x: 164; y: 68
        source: "assets/box_green.png"
        antialiasing: false
        onClicked: {
            rotation += 15
        }
    }

    ClickableImage {
        id: triangle
        x: 248; y: 68
        source: "assets/triangle_red.png"
        antialiasing: false
        onClicked: {
            rotation += 15
            scale += 0.05
        }
    }
}