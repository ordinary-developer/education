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
				
				PathPolyline {
					path: [
						Qt.point(220, 100),
						Qt.point(260, 20),
						Qt.point(300, 170),
						Qt.point(340, 60),
						Qt.point(340, 60),
						Qt.point(380, 100)
					]
				}
			}
		}
	}
}
