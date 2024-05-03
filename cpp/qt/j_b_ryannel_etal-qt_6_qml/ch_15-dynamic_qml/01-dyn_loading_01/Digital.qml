import QtQuick

Item {
	id: root
	
	property int speed: 0
	
	Text {
		id: text
		
		anchors.centerIn: parent
		font.pixelSize: parent.height * 0.4
		text: root.speed + " kph"
	}
}
