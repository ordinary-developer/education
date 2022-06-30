import QtQuick

Item {
	id: root
	width: 240
	height: 240
		
	Row {
		id: row
		anchors.centerIn: parent
		spacing: 20
		BlueSquare {}
		GreenSquare {}
		RedSquare {}
	}
}
