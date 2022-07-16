import QtQuick 2.8

Rectangle {
	id: root
	width: 540; height: 240
	color: "#4A4A4A"
	
	Rectangle {
		id: rect1
		x: 12; y: 12
		width: 76; height: 96
		color: "lightsteelblue"
	}

	Rectangle {
		id: rect2
		x: 112; y: 12
		width: 76; height: 96
		border.color: "lightsteelblue"
		border.width: 4
		radius: 8
	}
	
	Rectangle {
		id: rect3
		x: 212; y: 12
		width: 76; height: 96
		color: Qt.rgba(Math.random(), Math.random(), Math.random(), 1)
	}
	
	Rectangle {
		id: rect4
		x: 312; y: 12
		width: 176; height: 96
		gradient: Gradient {
			GradientStop { position: 0.0; color: "lightsteelblue" }
			GradientStop { position: 1.0; color: "slategray" }
		}
		border.color: "slategray"
	}
}
