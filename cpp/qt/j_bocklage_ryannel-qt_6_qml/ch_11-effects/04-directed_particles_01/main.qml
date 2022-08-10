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
			lifeSpan: 6400
			lifeSpanVariation: 400
			size: 32
			velocity: AngleDirection {
				angle: 0
				angleVariation: 15
				magnitude: 100
				magnitudeVariation: 50
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
