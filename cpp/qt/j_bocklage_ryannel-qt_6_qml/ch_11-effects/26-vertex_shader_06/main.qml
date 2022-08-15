import QtQuick

Window {
	id: mainRoot

	visible: true
	width: 500; height: 260	
	
	Rectangle {
		id: rectRoot
		width: 480; height: 240
		color: '#1e1e1e'		
		
		GenieEffect {
			source: Image { source: 'lighthouse.jpg' }
			MouseArea {
				anchors.fill: parent
				onClicked: parent.minimized = !parent.minimized
			}
		}
	}
}
