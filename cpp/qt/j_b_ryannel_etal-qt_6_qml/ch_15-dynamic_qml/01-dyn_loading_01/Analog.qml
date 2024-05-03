import QtQuick

Item {
	id: root
	
	property int speed: 0
	
	Rectangle {
		anchors.centerIn: parent
		
		width: 240
		height: 240
		
		radius: 120
		
		color: "lightGray"
	}
	
	Rectangle {
		id: needle
		
		anchors.right: parent.horizontalCenter
		anchors.top: parent.verticalCenter
		
		width: 120
		height: 2
		
		color: "red"
		
		transformOrigin: Item.Right
		rotation: -45 + root.speed
	}
	
	Repeater {
		model: 11
		delegate: Item {
			id: delegate
			
			required property int index
			
			anchors.right: parent.horizontalCenter
			anchors.top: parent.verticalCenter
			
			width: 140
			height: 2
			
			transformOrigin: Item.Right
			rotation: -45 + index * 270 / 10
			
			Rectangle {
				anchors.left: parent.left
				anchors.top: parent.top
				anchors.bottom: parent.bottom
				anchors.leftMargin: 16
				
				width: 8
				
				color: "black"
			}
			
			Text {
				anchors.horizontalCenter: parent.left
				anchors.verticalCenter: parent.top
				
				text: delegate.index * 270 / 10
				
				rotation: 45 - delegate.index * 270 / 10
			}
		}
	}
}
