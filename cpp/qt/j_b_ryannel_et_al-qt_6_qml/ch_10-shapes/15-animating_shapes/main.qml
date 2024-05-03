import QtQuick
import QtQuick.Shapes

Window {
	id: root

	visible: true
	width: 620; height: 620	
	
	Rectangle {
		id: rect
		width: 600
		height: 600	
		
		Shape {
			anchors.centerIn: parent
			
			ShapePath {
				id: shapepath
				
				property real t: 0.0
				
				NumberAnimation on t { from: 0.0; to: 1.0; duration: 500; loops: Animation.Infinite; running: true }
				
				strokeWidth: 3
				strokeColor: "darkGray"
				fillColor: "lightGray"
				
				startX: -40; startY: 200
				
				PathArc { x: 40; y: 200; radiusX: 200; radiusY: 200; useLargeArc: true }
				PathLine { x: 40; y: 120 }
				PathArc { x: -40; y: 120; radiusX: 120; radiusY: 120; useLargeArc: true; direction: PathArc.Counterclockwise }
				PathLine { x: -40; y: 200 }
				
				PathMove { x: -20+(1.0-shapepath.t)*20; y: 80 + shapepath.t*50 }
				PathArc { x: 20-(1.0-shapepath.t)*20; y: 80 + shapepath.t*50; radiusX: 20*shapepath.t; radiusY: 20*shapepath.t; useLargeArc: true }
				PathArc { x: -20+(1.0-shapepath.t)*20; y: 80 + shapepath.t*50; radiusX: 20*shapepath.t; radiusY: 20*shapepath.t; useLargeArc: true }				
			
				PathMove { x: -20; y: 130 + shapepath.t*50 }
				PathArc { x: 20; y: 130 + shapepath.t*50; radiusX: 20; radiusY: 20; useLargeArc: true }
				PathArc { x: -20; y: 130 + shapepath.t*50; radiusX: 20; radiusY: 20; useLargeArc: true }
				
				PathMove { x: -20; y: 180 + shapepath.t*50 }
				PathArc { x: 20; y: 180 + shapepath.t*50; radiusX: 20; radiusY: 20; useLargeArc: true }
				PathArc { x: -20; y: 180 + shapepath.t*50; radiusX: 20; radiusY: 20; useLargeArc: true }
			
				PathMove { x: -20+shapepath.t*20; y: 230 + shapepath.t*50 }
				PathArc { x: 20-shapepath.t*20; y: 230 + shapepath.t*50; radiusX: 20*(1.0-shapepath.t); radiusY: 20*(1.0-shapepath.t); useLargeArc: true }
				PathArc { x: -20+shapepath.t*20; y: 230 + shapepath.t*50; radiusX: 20*(1.0-shapepath.t); radiusY: 20*(1.0-shapepath.t); useLargeArc: true }            			}
		}
	}
}
