import QtQuick 2.8
import QtQuick.Controls 2.2


ApplicationWindow {
	visible: true
	width: 200
	height: 200
	title: "Controls"

	header: ToolBar {
		Button {
			text: "Quit"
			onClicked: Qt.quit()
		}
	}
	
	footer: ToolBar {
		id: statusbar
		Label {
			id: statuslbl
		}
	}
	
	ProgressBar {
		x: 0
		y: 0
		width: parent.width
		height: parent.height / 2
		value: slider.value
	}
	
	Dial {
		id: slider
		x: 0
		y: parent.height / 2
		width: parent.width
		height: parent.height / 2
		value: 0.75
		stepSize: 0.1
		onValueChanged: statuslbl.text = slider.value
	}
}
