import QtQuick

Item {
	id: root
	anchors.fill: parent
	anchors.margins: 1
	property color color: 'red'
	
	Rectangle {
		anchors.fill: parent
		color: 'transparent'
		border.color: root.color
		border.width: 2
		opacity: 0.8
	}
}