import QtQuick

Rectangle {
	id: root
	width: 200
	height: 80
	color: "linen"
	
	TLineEditV1 {
		id: input1
		x: 8; y: 8
		focus: true
		text: "Text Input 1"
		KeyNavigation.tab: input2
	}
	
	TLineEditV1 {
		id: input2
		x: 8; y: 36
		text: "Text Input 2"
		KeyNavigation.tab: input1
	}
}
