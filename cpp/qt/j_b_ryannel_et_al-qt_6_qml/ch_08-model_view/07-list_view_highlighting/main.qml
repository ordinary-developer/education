import QtQuick
import QtQuick.Controls


ApplicationWindow {
	visible: true
	width: 640
	height: 480
	
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
		
		GreenBox {
			width: ListView.view ? ListView.view.width : 0
		}
	}
}
