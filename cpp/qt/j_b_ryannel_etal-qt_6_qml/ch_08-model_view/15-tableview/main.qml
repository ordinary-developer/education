import QtQuick
import QtQuick.Controls


Window {
	id: root
	
	visible: true
    width: 320
    height: 320
	
	Background {
		anchors.fill: parent
		
		TableView {
			id: view
			anchors.fill: parent
			anchors.margins: 20
			
			rowSpacing: 5
			columnSpacing: 5
			
			clip: true
			
			model: tableModel
			delegate: cellDelegate
		}
	}
	
	Component {
		id: cellDelegate
		
		GreenBox {
			id: wrapper
			
			required property string display
			
			implicitHeight: 40
			implicitWidth: 40
			
			Text {
				anchors.centerIn: parent
				text: wrapper.display
			}
		}
	}
}
