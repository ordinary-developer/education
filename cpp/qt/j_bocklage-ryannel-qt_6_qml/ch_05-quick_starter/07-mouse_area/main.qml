import QtQuick 2.8

Rectangle {
	id: root
	width: 240; height: 240
	color: "white"
	
	Rectangle {
		id: rect1
		x: 12; y: 12
		width: 76; height: 96
		color: "lightsteelblue"
		MouseArea {
			id: area
			width: parent.width
			height: parent.height
			onClicked: rect2.visible = !rect2.visible
		}
	}
	
	Rectangle {
		id: rect2
		x: 112; y: 12
		width: 76; height: 96
		border.color: "lightsteelblue"
		border.width: 4
		radius: 8
	}
}
