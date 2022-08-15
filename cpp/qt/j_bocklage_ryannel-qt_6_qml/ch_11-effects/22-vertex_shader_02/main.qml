import QtQuick

Window {
	id: main_root

	visible: true
	width: 500; height: 260	
	
	Rectangle {
		id: root
		width: 480; height: 240
		color: '#1e1e1e'		
		
		Image {
			id: sourceImage
			width: 160; height: width
			source: "lighthouse.jpg"
			visible: false
		}
		
		Rectangle {
			width: 160; height: width
			anchors.centerIn: parent
			color: '#333333'
		}
		
		ShaderEffect {
			id: genieEffect
			width: 160; height: width
			anchors.centerIn: parent
			property variant source: sourceImage
			property bool minimized: false
			
			property real minimize: 0.0
			
			SequentialAnimation on minimize {
				id: animMinimize
				running: genieEffect.minimized
				PauseAnimation { duration: 300 }
				NumberAnimation { to: 1; duration: 700; easing.type: Easing.InOutSine }
				PauseAnimation { duration: 1000 }
			}
			
			SequentialAnimation on minimize {
				id: animNormalize
				running: !genieEffect.minimized
				NumberAnimation { to: 0; duration: 700; easing.type: Easing.InOutSine }
				PauseAnimation { duration: 1300 }
			}
			
			vertexShader: "genie1.vert.qsb"
			
			MouseArea {
				anchors.fill: parent
				onClicked: genieEffect.minimized = !genieEffect.minimized
			}
		}
	}
}
