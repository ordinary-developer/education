import QtQuick

Image {
	id: root
	signal clicked
	
	MouseArea {
		anchors.fill: parent
		onClicked: root.clicked()
	}
}
