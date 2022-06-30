import QtQuick

Item {
	id: root
	width: 160
	height: 160
		
	Flow {
		anchors.fill: parent
		anchors.margins: 20
		spacing: 20
		RedSquare { }
		BlueSquare { }
		GreenSquare { }
	}
}
