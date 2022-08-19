import QtQuick

Window {
	id: mainRoot

	visible: true
	width: root.width; height: root.height
	
	Rectangle {
		id: root
		width: 360
		height: 360
		color: '#000'
		
		GridView {
			id: view
			anchors.fill: parent
			cellWidth: width / 4
			cellHeight: cellWidth
			delegate: Rectangle {
				required property var modelData
				width: view.cellWidth
				height: view.cellHeight
				color: modelData.value
			}
		}
		
		function request() {
			const xhr = new XMLHttpRequest();
		
			xhr.onreadystatechange = function() {
				if (xhr.readyState === XMLHttpRequest.HEADERS_RECEIVED) {
					print('HEADERS_RECEIVED')
				}
				else if (xhr.readyState === XMLHttpRequest.DONE) {
					print('DONE');
					const response = JSON.parse(xhr.responseText.toString());					
					view.model = response.colors;
				}
			};
		
			xhr.open("GET", "colors.json");
			xhr.send()
		}
		
		Component.onCompleted: {
			request()
		}		
	}
}
