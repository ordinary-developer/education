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
				
				fillGradient: LinearGradient {
					x1: 50; y1: 300
					x2: 150; y2: 280
					
					GradientStop { position: 0.0; color: "lightgreen" }
					GradientStop { position: 0.7; color: "yellow" }
					GradientStop { position: 1.0; color: "darkgreen" }
				}
				
				startX: 20; startY: 340
				
				PathLine {
					x: 180
					y: 340
				}
				
				PathArc {
					x: 20
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
