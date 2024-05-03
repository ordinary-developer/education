import QtQuick

Window {
	id: main_root

	visible: true
	width: 500; height: 260	
	
	Rectangle {
		id: root
		width: 480; height: 240
		color: '#1e1e1e'		
		
		Row {
			anchors.centerIn: parent
			spacing: 20
			
			Image {
				id: sourceImage
				width: 160; height: width
				source: "coastline.jpg"
			}
			
			ShaderEffect {
				width: 160; height: width
				property variant source: sourceImage
				property real frequency: 8
				property real amplitude: 0.1
				property real time: 0.0
				NumberAnimation on time {
					from: 0; to: Math.PI * 2; duration: 1000; loops: Animation.Infinite
				}
				
				fragmentShader: "wave.frag.qsb"
			}
		}
	}
}
