import QtQuick

Rectangle {
	id: root
	width: 48; height: 48
	color: "green"
	signal clicked
	property bool active: false
	border.color: active ? "#555555" : "#f0f0f0"
	border.width: 2
	
	MouseArea {
		id: area
		anchors.fill: parent
		onClicked: {
			root.clicked()
		}
	}
}
