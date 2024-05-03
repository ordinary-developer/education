import QtQuick
import QtQuick.Particles

Window {
	id: main_root

	visible: true
	width: 500; height: 260	
	
	Rectangle {
		id: root
		width: 400; height: 400
		color: "#333333"
		
		property var images: [
			"box_blue.png",
			"box_red.png",
			"box_green.png",
			"circle_blue.png",
			"circle_red.png",
			"circle_green.png",
			"triangle_blue.png",
			"triangle_red.png",
			"triangle_green.png",
		]
		
		ParticleSystem {
			id: particleSystem
		}
		
		Emitter {
			id: emitter
			anchors.fill: root
			anchors.margins: 32
			system: particleSystem
			emitRate: 4
			lifeSpan: 2000
		}
		
		ItemParticle {
			id: particle
			system: particleSystem
			delegate: itemDelegate
		}
		
		Component {
			id: itemDelegate
			
			Item {
				id: container
				width: 32 * Math.ceil(Math.random() * 3)
				height: width
				Image {
					anchors.fill: parent
					anchors.margins: 4
					source: root.images[Math.floor(Math.random() * 9)]
				}
			}
		}
	}
}
