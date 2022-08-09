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
				
				fillColor: "lightgreen"
				
				startX: 20; startY: 140
				
				PathLine {
					x: 180
					y: 140
				}
				
				PathArc {
					x: 20
					y: 140
					radiusX: 80
					radiusY: 80
					direction: PathArc.Counterclockwise
					useLargeArc: true
				}
			}
		}
	}
}
