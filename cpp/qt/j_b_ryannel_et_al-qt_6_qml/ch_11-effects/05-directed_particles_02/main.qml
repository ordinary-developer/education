import QtQuick
import QtQuick.Particles

Window {
	id: root

	visible: true
	width: 480; height: 160	
	
	Rectangle {
		id: rect
		width: 500
		height: 180	
		color: "#1f1f1f"
		
		ParticleSystem {
			id: particleSystem
		}
		
		Emitter {
			id: emitter
			anchors.left: parent.left
			anchors.verticalCenter: parent.verticalCenter
			width: 1; height: 1
			system: particleSystem
			emitRate: 10
			lifeSpan: 6400
			lifeSpanVariation: 400
			size: 32
			
			velocity: AngleDirection {
				angle: -45
				angleVariation: 0
				magnitude: 100
			}
			
			acceleration: AngleDirection {
				angle: 90
				magnitude: 25
			}
		}
		
		ImageParticle {
			source: "star.png"
			system: particleSystem
			color: '#FFD700'
			colorVariation: 0.2
			rotation: 0
			rotationVariation: 45
			rotationVelocity: 15
			rotationVelocityVariation: 15
			entryEffect: ImageParticle.Scale
		}
	}
}
