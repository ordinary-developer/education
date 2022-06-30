import QtQuick

Item {
	id: root
	width: 252
	height: 252
	property variant colorArray: ["#00bde3", "#67c111", "#ea7025"]
	
	Grid {
		anchors.fill: parent
		anchors.margins: 8
		spacing: 4
		Repeater {
			model: 16
			delegate: Rectangle {
				required property int index
				property int colorIndex: Math.floor(Math.random() * 3)
				
				width: 56; height: 56
				color: root.colorArray[colorIndex]
				border.color: Qt.lighter(color)
				
				Text {
					anchors.centerIn: parent
					color: "#f0f0f0"
					text: "Cell " + parent.index
				}
			}
		}
	}
}
