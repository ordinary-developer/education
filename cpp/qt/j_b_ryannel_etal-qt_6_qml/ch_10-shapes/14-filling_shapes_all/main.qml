import QtQuick
import QtQuick.Shapes

Window {
	id: root

	visible: true
	width: 420; height: 420	
	
	Rectangle {
		id: rect
		width: 400
		height: 400
		
		// solid
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
		
		// conical
		Shape {
			ShapePath {
				strokeWidth: 3
				strokeColor: "darkgray"
				
				fillGradient: ConicalGradient {
					centerX: 300; centerY: 100
					angle: 45
					
					GradientStop { position: 0.0; color: "lightgreen" }
					GradientStop { position: 0.7; color: "yellow" }
					GradientStop { position: 1.0; color: "darkgreen" }
				}
				
				startX: 220; startY: 140
				
				PathLine {
					x: 380
					y: 140
				}
				
				PathArc {
					x: 220
					y: 140
					radiusX: 80
					radiusY: 80
					direction: PathArc.Counterclockwise
					useLargeArc: true
				}
			}
		}
		
		// linear
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
		
		// radial
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
		
		
		// solid
		Text {
			x: 0
			y: 150
			width: 200
			
			text: "solid color"
			horizontalAlignment: Text.AlignHCenter
		}
		
		// conical
		Text {
			x: 200
			y: 150
			width: 200
			
			text: "ConicalGradient"
		}
		
		// linear
		Text {
			x: 0
			y: 350
			width: 200
			
			text: "LinearGradient"
			horizontalAlignment: Text.AlignHCenter
		}
		
		// radial
		Text {
			x: 200
			y: 350
			width: 200
			
			text: "RadialGradient"
			horizontalAlignment: Text.AlignHCenter
		}
		
	}
}
