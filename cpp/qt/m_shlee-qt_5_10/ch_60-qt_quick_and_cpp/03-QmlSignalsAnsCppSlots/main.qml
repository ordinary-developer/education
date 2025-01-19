import QtQuick 2.8
import QtQuick.Controls 2.2
import QtQuick.Window 2.2

Window {
	visible: true
	width: 150
	height: 150
	Column {
		anchors.centerIn: parent
		Button {
			signal infoClicked(string str)
			objectName: "InfoButton"
			text: "info"
			onClicked: infoClicked("Information")
		}
		Button {
			signal quitClicked()
			objectName: "QuitButton"
			text: "Quit"
			onClicked: quitClicked()
		}
	}
}
