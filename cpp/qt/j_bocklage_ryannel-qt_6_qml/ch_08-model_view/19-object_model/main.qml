import QtQuick
import QtQml.Models

Window {
	id: root
	
	visible: true
    width: 350
    height: 350
	
	Rectangle {
		width: 320
		height: 320
		
		gradient: Gradient {
			GradientStop { position: 0.0; color: "#f6f6f6" }
			GradientStop { position: 1.0; color: "#d7d7d7" }
		}
	}
	
	ObjectModel {
		id: itemModel
		
		Rectangle { height: 60; width: 80; color: "#157efb" }
		Rectangle {
			height: 20;
			width: 300;
			color: "black";
			Text {
				anchors.centerIn: parent;
				color: "black";
				text: "Hello QML"
			}
		}
		Rectangle { height: 40; width: 40; radius: 10; color: "#fc1a1c" }
			
	}
	
	ListView {
		anchors.fill: parent
		
		anchors.margins: 10
		spacing: 5
		
		model: itemModel
	}
}
