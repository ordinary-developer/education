import QtQuick
import QtQuick.Shapes

Shape {
	ShapePath {
		strokeWidth: 3
		strokeColor: "red"
		
		PathMultiline {
			paths: [
				[
					Qt.point(-5, 0),
					Qt.point(5, 0),
				],
				[
					Qt.point(0, -5),
					Qt.point(0, 5),
				]
			]
		}
	}
}