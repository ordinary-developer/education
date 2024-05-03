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
				
				startX: 220; startY: 300
				
				PathCubic {
					x: 380; y: 300
					control1X: 260; control1Y: 250
					control2X: 360; control2Y: 350
				}
			}
		}
	}
}
