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
			anchors.centerIn: parent
			width: 160; height: 80
			system: particleSystem
			emitRate: 10
			lifeSpan: 1000
			lifeSpanVariation: 500
			size: 16
			sizeVariation: 32
			Tracer { color: 'green' }
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
