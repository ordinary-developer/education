import QtQuick
import "http://localhost:8080" as Remote

Window {
	id: mainRoot

	visible: true
	width: root.width; height: root.height
	
	Rectangle {
		id: root
		width: 320
		height: 320
		color: 'blue'
		
		Remote.Button {
			anchors.centerIn: parent
			text: qsTr('Quit')
			onClicked: Qt.quit()
		}
	}
}
