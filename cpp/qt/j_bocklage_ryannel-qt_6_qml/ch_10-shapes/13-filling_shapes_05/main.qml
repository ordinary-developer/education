import QtQuick
import QtQuick.Shapes

Window {
	id: root

	visible: true
	width: 620; height: 620	
	
	Rectangle {
		id: rect
		width: 200
		height: 200
		
		Shape {
			ShapePath {
				strokeWidth: 3
				strokeColor: "darkgray"
				
				fillGradient: RadialGradient {
					centerX: 300; centerY: 250; centerRadius: 120
					focalX: 300; focalY: 220; focalRadius: 10
					
					GradientStop { position: 0.0; color: "lightgreen" }
					GradientStop { position: 0.7; color: "yellow" }
					GradientStop { position: 1.0; color: "darkgreen" }
				}
				
				startX: 220; startY: 340
				
				PathLine {
					x: 380
					y: 340
				}
				
				PathArc {
					x: 220
					y: 340
					
					radiusX: 80
					radiusY: 80
					direction: PathArc.Counterclockwise
					useLargeArc: true
				}
			}
		}
		
	}
}
