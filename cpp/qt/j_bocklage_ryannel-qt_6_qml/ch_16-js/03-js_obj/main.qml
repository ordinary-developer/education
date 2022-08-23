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
		
		property var objData: {
			k: 'value'
		}
		
		Timer {
			id: timerUpdater
			interval: 100
			running: true
			repeat: true
			onTriggered: {
				var d = new Date();
				console.log(d.getSeconds());
			}
		}
		
		function doIt() {
			console.log("doIt()");
		}
		
		Component.onCompleted: {
			var keys = Object.keys(root);
			for (var i = 0; i < keys.length; i++) {
				var key = keys[i];
				console.log(key + ' : ' + root[key]);
			}
			
			var data = JSON.stringify(objData);
			console.log(data);
			var obj = JSON.parse(data);
			console.log(obj);
			
			root["doIt"]();
			var fn = root["doIt"];
			fn.call();
		}		
    }
}
