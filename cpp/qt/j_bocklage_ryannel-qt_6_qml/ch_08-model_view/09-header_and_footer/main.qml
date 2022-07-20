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
			anchors.fill: parent
			anchors.margins: 20
			
			clip: true
			
			model: 4
			delegate: numberDelegate
			header: headerComponent
			footer: footerComponent
			
			spacing: 2
		}
		
		Component {
			id: headerComponent
			
			YellowBox {
				width: (ListView.view ? ListView.view.width : 0)
				height: 20
				text: 'Header'
			}
		}
		
		Component {
			id: footerComponent
			
			YellowBox {
				width: (ListView.view ? ListView.view.width : 0)
				height: 20
				text: 'Footer'
			}
		}
		
		Component {
			id: numberDelegate
			
			GreenBox {
				required property int index
				
				width: ListView.view.width
				height: 40
				
				text: 'Item #' + index
			}
		}
	}
}

