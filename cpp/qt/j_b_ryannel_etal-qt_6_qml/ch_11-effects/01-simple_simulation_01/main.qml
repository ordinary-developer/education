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
			endSize: 32
			Tracer { color: 'green' }
		}
		
		ImageParticle {
			source: "particle.png"
			system: particleSystem
		}
	}
}
