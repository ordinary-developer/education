import QtQuick

Item {
	id: root
	width: 240
	height: 240
		
	Grid {
		id: grid
		rows: 2
		columns: 2
		anchors.centerIn: parent
		spacing: 8
		RedSquare {}
		RedSquare {}
		RedSquare {}
		RedSquare {}
	}
}
