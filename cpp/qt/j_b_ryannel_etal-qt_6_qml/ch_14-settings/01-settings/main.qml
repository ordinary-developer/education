import QtQuick
import Qt.labs.settings 1.0

Window {
	id: mainRoot

	visible: true
	width: root.width; height: root.height
	
	Rectangle {
		id: root
		width: 320
		height: 240
		color: '#fff'
		
		Settings {
			property alias color: root.color
		}
		
		MouseArea {
			anchors.fill: parent
			onClicked: root.color = Qt.hsla(Math.random(), 0.5, 0.5, 1.0);
		}
	}
}
