import QtQuick
import QtQuick.Controls


ApplicationWindow {
	visible: true
	width: 640
	height: 480
	
	ListView {
		anchors.fill: parent
		anchors.margins: 20
		clip: true
		model: 100
		delegate: GreenBox {
			required property int index
			width: 40
			height: 40
			text: index
		}
		spacing: 5
	}
}
