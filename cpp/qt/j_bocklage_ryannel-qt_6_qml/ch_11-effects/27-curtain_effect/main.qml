import QtQuick

Window {
	id: mainRoot

	visible: true
	width: root.width; height: root.height
	
	Item {
		id: root
		width: background.width; height: background.height
		
		Image {
			id: background
			anchors.centerIn: parent
			source: 'background.png'
		}
		
		Text {
			anchors.centerIn: parent
			font.pixelSize: 48
			color: '#efefef'
			text: 'Qt 6 Book'
		}
		
		CurtainEffect {
			id: curtain
			anchors.fill: parent
		}
		
		MouseArea {
			anchors.fill: parent
			onClicked: curtain.open = !curtain.open
		}
	}
}
