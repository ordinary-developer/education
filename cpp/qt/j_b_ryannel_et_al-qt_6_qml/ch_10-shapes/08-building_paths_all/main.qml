import QtQuick
import QtQuick.Shapes

Window {
	id: root

	visible: true
	width: 620; height: 420	
	
	Rectangle {
		id: rect
		width: 600
		height: 400
		
		// PathLine
		Shape {
			ShapePath {
				strokeWidth: 3
				strokeColor: "darkgray"
				
				startX: 20; startY: 70
				
				PathLine {
					x: 180
					y: 130
				}
			}
		}
		
		// PathPolyLine
		Shape {
			ShapePath {
				strokeWidth: 3
				strokeColor: "darkgray"
				
				PathPolyline {
					path: [
						Qt.point(220, 100),
						Qt.point(260, 20),
						Qt.point(300, 170),
						Qt.point(340, 60),
						Qt.point(380, 100)
					]
				}
			}
		}
		
		// PathArc
		Shape {
			ShapePath {
				strokeWidth: 3
				strokeColor: "darkgray"
				
				startX: 420; startY: 100
				
				PathArc {
					x: 580; y: 180
					radiusX: 120; radiusY: 120
				}
			}
		}
		
		// PathQuad
		Shape {
			ShapePath {
				strokeWidth: 3
				strokeColor: "darkgray"
				
				startX: 20; startY: 300
				
				PathQuad {
					x: 180; y: 300
					controlX: 60; controlY: 250
				}
			}
		}
		
		// PathCubic
		Shape {
			ShapePath {
				strokeWidth: 3
				strokeColor: "darkgray"
				
				startX: 220; startY: 300
				
				PathCubic {
					x: 380; y: 300
					control1X: 260; control1Y: 250
					control2X: 360; control2Y: 350
				}
			}
		}
		
		// PathCurve
		Shape {
			ShapePath {
				strokeWidth: 3
				strokeColor: "darkgray"
				
				startX: 420; startY: 300
				
				PathCurve { x: 460; y: 220 }
				PathCurve { x: 500; y: 370 }
				PathCurve { x: 540; y: 270 }
				PathCurve { x: 580; y: 300 }
			}
		}
		
		
		// PathLine
		Marker { x: 20; y: 70 }
		Marker { x: 180; y: 130 }
		
		// PathPolyLine
		Marker { x: 220; y: 100 }
		Marker { x: 260; y: 20 }
		Marker { x: 300; y: 170 }
		Marker { x: 340; y: 60 }
		Marker { x: 380; y: 100 }
		
		// PathArc
		Marker { x: 420; y: 100 }
		Marker { x: 580; y: 180 }
		
		// PathQuad
		Marker { x: 20; y: 300 }
		Marker { x: 180; y: 300 }
		Marker { x: 60; y: 250 }
		
		// PathCubic
		Marker { x: 220; y: 300 }
		Marker { x: 380; y: 300 }
		Marker { x: 260; y: 250 }
		Marker { x: 360; y: 350 }
		
		// PathCurve
		Marker { x: 420; y: 300 }
		Marker { x: 460; y: 220 }
		Marker { x: 500; y: 370 }
		Marker { x: 540; y: 270 }
		Marker { x: 560; y: 300 }
		
		
		// PathLine
		Text {
			x: 0
			y: 180
			width: 200
			
			text: "Pathline"
			horizontalAlignment: Text.AlignHCenter
		}
		
		// PathPolyLine
		Text {
			x: 200
			y: 180
			width: 200
			
			text: "PathPolyline"
			horizontalAlignment: Text.AlignHCenter
		}
		
		// PathArc
		Text {
			x: 400
			y: 180
			width: 200
			
			text: "PathArc"
			horizontalAlignment: Text.AlignHCenter
		}
		
		// PathQuad
		Text {
			x: 0
			y: 380
			width: 200
			
			text: "PathQuad"
			horizontalAlignment: Text.AlignHCenter
		}
		
		// PathCubic
		Text {
			x: 200
			y: 380
			width: 200
			
			text: "PathCubic"
			horizontalAlignment: Text.AlignHCenter
		}
		
		// PathCurve
		Text {
			x: 400
			y: 380
			width: 200
			
			text: "PathCurve"
			horizontalAlignment: Text.AlignHCenter
		}
	}
}
