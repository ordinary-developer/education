import QtQuick
import QtQuick.Controls


ApplicationWindow {
	visible: true
	width: 640
	height: 480
	
	Background {
		width: 220
		height: 300
		
		GridView {
			id: view
			anchors.fill: parent
			anchors.margins: 20
			
			clip: true
			
			model: 100
			
			cellWidth: 45
			cellHeight: 45
			
			delegate: GreenBox {
				required property int index
				width: 40
				height: 40
				text: index
			}
		}
	}
}
