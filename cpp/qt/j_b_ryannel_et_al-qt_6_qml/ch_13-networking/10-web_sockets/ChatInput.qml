import QtQuick

FocusScope {
	id: root
	
	property alias text: input.text
	signal accepted(string text)
	
	width: 240
	height: 32
	
	Rectangle {
		anchors.fill: parent
		color: '#000'
		border.color: '#fff'
		border.width: 2
	}
	
	TextInput {
		id: input
		anchors.left: parent.left
		anchors.right: parent.right
		anchors.verticalCenter: parent.verticalCenter
		anchors.leftMargin: 4
		anchors.rightMargin: 4
		color: '#fff'
		focus: true
		onAccepted: function() {
			root.accepted(text)
		}
	}
}
