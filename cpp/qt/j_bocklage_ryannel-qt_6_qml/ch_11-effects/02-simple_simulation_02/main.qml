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
			width: 20; height: 20
			system: particleSystem
			emitRate: 40
			lifeSpan: 2000
			lifeSpanVariation: 500
			size: 64
			sizeVariation: 32
			Tracer { color: 'green' }
		}
		
		ImageParticle {
			source: "particle.png"
			system: particleSystem
		}
	}
}
