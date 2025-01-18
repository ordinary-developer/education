import QtQuick 2.8

Rectangle {
	color: "lightgreen"
	width: 100
	height: 100
	Text {
		objectName: "text"
		anchors.centerIn: parent
		text: "Hello QML"
		
		function setFontSize(newSize) {
			var info = "PreviousSize = " + font.pixelSize
			font.pixelSize = newSize
			return info
		}
	}
}
