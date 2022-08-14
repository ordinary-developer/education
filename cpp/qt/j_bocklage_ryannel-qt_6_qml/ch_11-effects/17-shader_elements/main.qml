import QtQuick
import QtQuick.Particles

Window {
	id: main_root

	visible: true
	width: 500; height: 260	
	
	Rectangle {
		width: 480; height: 240
		color: '#1e1e1e'
		
		Row {
			anchors.centerIn: parent
			spacing: 20
			
			Image {
				id: sourceImage
				width: 80; height: width
				source: 'tulips.jpg'
			}
			
			ShaderEffect {
				id: effect
				width: 80; height: width
				property variant source: sourceImage
			}			
			
			ShaderEffect {
				id: effect2
				width: 80; height: width
				property variant source: sourceImage
				vertexShader: "default.vert.qsb"
				fragmentShader: "default.frag.qsb"
			}
		}
	}
}
