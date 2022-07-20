import QtQuick
import QtQuick.Controls


ApplicationWindow {
	visible: true
	width: 640
	height: 480
	
	Column {
		
		spacing: 2
		
		Repeater {
			model: ["Enterprise", "Columbia", "Challenger", "Discovery", "Endeavour", "Atlantis" ]
			
			delegate : BlueBox {
				required property var modelData
				required property int index
				
				width: 100
				height: 32
				radius: 3
				
				text: modelData + ' (' + index + ')'
			}
		}
	}
}
