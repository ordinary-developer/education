import QtQuick

Item {
	id: root
	width: 120
	height: 240
		
	Column {
		id: column
		anchors.centerIn: parent
		spacing: 8
		RedSquare {}
		GreenSquare { width: 96 }
		BlueSquare {}
	}
}