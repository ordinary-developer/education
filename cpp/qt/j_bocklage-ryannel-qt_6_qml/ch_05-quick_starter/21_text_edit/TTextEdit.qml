import QtQuick

FocusScope {
	width: 96; height: 96
	
	Rectangle {
		anchors.fill: parent
		color: "lightsteelblue"
	}
	
	property alias text: input.text
	property alias input: input
	
	TextEdit {
		id: input
		anchors.fill: parent
		anchors.margins: 4
		focus: true
	}
}