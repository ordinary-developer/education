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
				
				startX: 20; startY: 300
				
				PathQuad {
					x: 180; y: 300
					controlX: 60; controlY: 250
				}
			}
		}
	}
}
