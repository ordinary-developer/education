import QtQuick

Window {
	id: mainRoot

	visible: true
	width: root.width; height: root.height
	
	Rectangle {
		id: root
		width: 320
		height: 480

		ListView {
			id: view
			anchors.fill: parent
			delegate: Thumbnail {
				required property var modelData
				width: view.width
				text: modelData.title
				iconSource: modelData.media.m
			}
		}
		
		function request() {
			const xhr = new XMLHttpRequest();
			
			xhr.onreadystatechange = function() {
				if (xhr.readyState === XMLHttpRequest.HEADERS_RECEIVED) {
					print('HEADERS_RECEIVED')
				}
				else if (xhr.readyState === XMLHttpRequest.DONE) {
					print('DONE')
					const response = JSON.parse(xhr.responseText.toString())
					view.model = response.items
				}
			};
			
			xhr.open(
				"GET",
				"http://api.flickr.com/services/feeds/photos_public.gne?format=json&nojsoncallback=1&tags=munich");
			xhr.send();
		}
		
		Component.onCompleted: {
			root.request()
		}
	}
}
