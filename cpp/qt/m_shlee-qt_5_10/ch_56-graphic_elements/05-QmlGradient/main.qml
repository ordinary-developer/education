import QtQuick 2.8

Rectangle {
    width: 200
    height: 200
    gradient: Gradient {
        GradientStop { position: 0.0; color: "blue" }
        GradientStop { position: 0.7; color: "gold" }
        GradientStop { position: 1.0; color: "silver" }
    }
    rotation: 30
    scale: 1.5
}
