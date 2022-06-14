import QtQuick 2.8

Rectangle {
	id: root
	width: 240; height: 240
	color: "white"
	
	Rectangle {
		id: button
		x: 12; y: 12
		width: 116; height: 26
		color: "lightsteelblue"
		border.color: "slategrey"
		Text {
			anchors.centerIn: parent
			text: "Start"
		}
		MouseArea {
			anchors.fill: parent
			onClicked: {
				status.text = "Button clicked!"
			}
		}
	}
	
	Text {
		id: status
		x: 12; y: 76
		width: 116; height: 26
		text: "waiting ..."
		horizontalAlignment: Text.AlignHCenter
	}
}
