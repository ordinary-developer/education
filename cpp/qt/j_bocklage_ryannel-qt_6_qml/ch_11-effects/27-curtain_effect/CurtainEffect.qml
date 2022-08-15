import QtQuick

ShaderEffect {
	anchors.fill: parent
	
	mesh: GridMesh {
		resolution: Qt.size(50, 50)
	}
	
	property real topWidth: open ? width : 20
	property real bottomWidth: topWidth
	property real amplitude: 0.1
	property bool open: false
	property variant source: effectSource
	
	Behavior on bottomWidth {
		SpringAnimation {
			easing.type: Easing.OutElastic;
			velocity: 250; mass: 1.5;
			spring: 0.5; damping: 0.05;
		}
	}
	
	Behavior on topWidth {
		NumberAnimation { duration: 1000 }
	}
	
	ShaderEffectSource {
		id: effectSource
		sourceItem: effectImage
		hideSource: true
	}
	
	Image {
		id: effectImage
		anchors.fill: parent
		source: 'fabric.png'
		fillMode: Image.Tile
	}
	
	vertexShader: 'curtain.vert.qsb'
	
	fragmentShader: 'curtain.frag.qsb'
}
