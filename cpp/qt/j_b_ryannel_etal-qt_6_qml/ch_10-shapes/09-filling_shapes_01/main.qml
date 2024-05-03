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
				fillColor: "orange"
				
				fillRule: ShapePath.OddEvenFill
				
				PathPolyline {
					path: [
						Qt.point(100, 20),
						Qt.point(150, 180),
						Qt.point(20, 75),
						Qt.point(180, 75),
						Qt.point(50, 180),
						Qt.point(100, 20),
					]
				}
			}
		}
		
		Shape {
			ShapePath {
				strokeWidth: 3
				strokeColor: "darkgray"
				fillColor: "orange"
				
				fillRule: ShapePath.WindingFill
				
				PathPolyline {
					path: [
						Qt.point(300, 20),
						Qt.point(350, 180),
						Qt.point(220, 75),
						Qt.point(380, 75),
						Qt.point(250, 180),
						Qt.point(300, 20),
					]
				}
			}
		}
	}
}
