import QtQuick
import QtQuick.Controls


ApplicationWindow {
	visible: true
	width: 640
	height: 480
	
	Rectangle {
		width: 480
		height: 300
		
		gradient: Gradient {
			GradientStop { position: 0.0; color: "#dbddde" }
			GradientStop { position: 1.0; color: "#5fc9f8" }
		}
		
		ListModel {
			id: theModel
			
			ListElement { number: 0 }
			ListElement { number: 1 }
			ListElement { number: 2 }
			ListElement { number: 3 }
			ListElement { number: 4 }
			ListElement { number: 5 }
			ListElement { number: 6 }
			ListElement { number: 7 }
			ListElement { number: 8 }
			ListElement { number: 9 }
		}
		
		Rectangle {
			property int count: 9
			
			anchors.left: parent.left
			anchors.right: parent.right
			anchors.bottom: parent.bottom
			anchors.margins: 20
			
			height: 40
			
			color: "#53d769"
			border.color: Qt.lighter(color, 1.1)
			
			Text {
				anchors.centerIn: parent
				
				text: "Add item!"
			}
			
			MouseArea {
				anchors.fill: parent
				
				onClicked: {
					theModel.append({"number": ++parent.count});
				}
			}
		}
		
		GridView {
			anchors.fill: parent
			anchors.margins: 20
			anchors.bottomMargin: 80
		
			clip: true
		
			model: theModel
			
			cellWidth: 45
			cellHeight: 45
			
			delegate: numberDelegate
		}
		
		Component {
			id: numberDelegate
			
			Rectangle {
				id: wrapper
				
				required property int index
				required property int number
				
				width: 40
				height: 40
				
				gradient: Gradient {
					GradientStop { position: 0.0; color: "#f8306a" }
					GradientStop { position: 1.0; color: "#fb5b40" }
				}
				
				Text {
					anchors.centerIn: parent
					
					font.pixelSize: 10
					
					text: wrapper.number
				}
				
				MouseArea {
					anchors.fill: parent
					
					onClicked: {
						if (wrapper.index == -1) {
							return;
						}
						
						theModel.remove(wrapper.index)
					}
				}
				
				GridView.onRemove: removeAnimation.start()
				
				SequentialAnimation {
					id: removeAnimation
					
					PropertyAction { target: wrapper; property: "GridView.delayRemove"; value: true }
					NumberAnimation { target: wrapper; property: "scale"; to: 0; duration: 250; easing.type: Easing.InOutQuad }
					PropertyAction { target: wrapper; property: "GridView.delayRemove"; value: false }
				}
				
				GridView.onAdd: addAnimation.start()
				
				SequentialAnimation {
					id: addAnimation
					NumberAnimation {
						target: wrapper
						property: "scale"
						from: 0
						to: 1
						duration: 250
						easing.type: Easing.InOutQuad
					}
				}
			}
		}
	}
}
