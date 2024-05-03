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
		
		ImageParticle {
			source: "particle.png"
			system: particleSystem
			color: '#FFD700'
			colorVariation: 0.2
			rotation: 0
			rotationVariation: 45
			rotationVelocityVariation: 15
			entryEffect: ImageParticle.Scale
		}
		
		Emitter {
			id: emitter
			anchors.left: parent.left
			anchors.verticalCenter: parent.verticalCenter
			width: 1; height: 20
			system: particleSystem
			emitRate: 40
			lifeSpan: 6400
			lifeSpanVariation: 400
			size: 32
			velocity: AngleDirection {
				angle: -90
				angleVariation: 25
				magnitude: 100
				magnitudeVariation: 25
			}
		}
		
		Gravity {
			width: 240; height: 240
			system: particleSystem
			magnitude: 50
			angle: 90
			Tracer {}
		}
		
	}
}

