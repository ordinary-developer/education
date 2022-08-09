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
				
				startX: 420; startY: 300
				
				PathCurve { x: 460; y: 220 }
				PathCurve { x: 500; y: 370 }
				PathCurve { x: 540; y: 270 }
				PathCurve { x: 580; y: 300 }
			}
		}
	}
}
