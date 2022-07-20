import QtQuick
import QtQuick.Controls


ApplicationWindow {
	visible: true
	width: 640
	height: 480
	
	Background {
		width: 240
		height: 300 
		
		ListView {
			id: view
			
			anchors.fill: parent
			anchors.margins: 20
			
			focus: true
			
			model: 100
			delegate: numberDelegate
			highlight: highlightComponent
			
			spacing: 5
			clip: true
		}
		
		Component {
			id: numberDelegate
			
			Item {
				id: wrapper
				
				required property int index
				
				width: ListView.view ? ListView.view.width: 0
				height: 40
				
				Text {
					anchors.centerIn: parent
					font.pixelSize: 10
					text: wrapper.index
				}
			}
		}
		
		Component {
			id: highlightComponent
			
			Item {
				width: ListView.view ? ListView.view.width : 0
				height: ListView.view ? ListView.view.currentItem.height : 0
				
				y: ListView.view ? ListView.view.currentItem.y : 0
				
				Behavior on y {
					SequentialAnimation {
						PropertyAnimation { target: hightlightRectangle; property: "opactiy"; to: 0; duration: 200 }
						NumberAnimation { duration: 1 }
						PropertyAnimation { target: hightlightRectangle; property: "opactiy"; to: 1; duration: 200 }
					}
				}
				
				GreenBox {
					id: hightlightRectangle
					anchors.fill: parent
				}
			}
		}
	}
}
