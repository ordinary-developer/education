import QtQuick

BrightSquare {
	id: root
	
	property int duration: 3000
	property Item ufo: ufo
	
	width: 600
	height: 400
	
	Image {
		anchors.fill: parent
		source: "qrc:/ufo_background.png"
	}
	
	ClickableImageV3 {
		id: ufo
		x: 20; y: root.height - height
		text: qsTr('rocket')
		source: "qrc:/ufo.png"
		onClicked: anim.restart()
	}
	
	SequentialAnimation {
		id: anim
		
		NumberAnimation {
			target: ufo
			properties: "y"
			to: 20
			duration: root.duration * 0.6
		}
		
		NumberAnimation {
			target: ufo
			properties: "x"
			to: 400
			duration: root.duration * 0.4
		}
	}
}
