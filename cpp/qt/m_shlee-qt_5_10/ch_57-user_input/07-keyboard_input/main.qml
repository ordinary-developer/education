import QtQuick 2.8

Rectangle {
	width: 200
	height: 100
	TextInput {
		anchors.centerIn: parent
		color: "red"
		text: "Text"
		font.pixelSize: 32
		focus: true
	}
}
