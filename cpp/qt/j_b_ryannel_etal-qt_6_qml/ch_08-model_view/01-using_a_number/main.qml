import QtQuick
import QtQuick.Controls


ApplicationWindow {
	visible: true
	width: 640
	height: 480
	
	Column {
		spacing: 2
		
		Repeater {
			model: 5
			delegate: BlueBox {
				required property int index
				width: 100
				height: 32
				text: index
			}
		}
	}
}
