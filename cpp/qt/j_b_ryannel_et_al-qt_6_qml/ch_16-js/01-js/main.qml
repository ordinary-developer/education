import QtQuick
import QtQuick.Controls

Window {
	id: mainRoot

	visible: true
	width: root.width; height: root.height
	
	Rectangle {
		id: root
		
		width: 1024
		height: 600
		
		Column {
			anchors.fill: parent
			spacing: 10
			
			Button {
				width: 200
				height: 300
				property bool checkedEx: false
				text: "Click to toggle"
				
				function doToggle() {
					checkedEx = !checkedEx;
				}
				
				onClicked: {
					doToggle();
					console.log('checked: ' + checked);
					console.log('checkedEx: ' + checkedEx);
				}
			}
			
			Button {
				width: 200
				height: width * 1.1 
				text: "another button"
				
				function log(msg) {
					console.log("Button > " + msg);
				}
				
				onClicked: {
					log();
					Qt.quit();
				}
			}
		}
		
    }
}
