import QtQuick

Image {
	source: "rocket.png"
	
	MouseArea {
		anchors.fill: parent
		drag.target: parent
		drag.axis: Drag.XandYAxis
	}
}
