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
				strokeColor: "darkGrey"
				
				startX: 420; startY: 100
				
				PathArc {
					x: 580; y: 180
					radiusX: 120; radiusY: 120
				}
			}
		}
	}
}
