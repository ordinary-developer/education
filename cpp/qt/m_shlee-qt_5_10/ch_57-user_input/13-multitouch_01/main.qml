import QtQuick 2.8

Rectangle {
	width: 400
	height: 400
	color: "black"
	
	MultiPointTouchArea {
		anchors.fill: parent
		minimumTouchPoints: 1
		maximumTouchPoints: 5
		touchPoints: [
			TouchPoint {},
			TouchPoint {},
			TouchPoint {},
			TouchPoint {},
			TouchPoint {}
		]
		Repeater {
			model: parent.touchPoints
			Rectangle {
				color: "white"
				x: modelData.x;
				y: modelData.y;
				width: 30;
				height: 30
				visible: modelData.pressed
			}
		}
	}
}
