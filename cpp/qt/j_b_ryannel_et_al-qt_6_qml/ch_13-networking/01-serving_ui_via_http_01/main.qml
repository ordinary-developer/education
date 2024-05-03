import QtQuick

Window {
	id: mainRoot

	visible: true
	width: root.width; height: root.height
	
	Loader {
		id: root
		source: 'http://localhost:8080/RemoteComponent.qml'
		onLoaded: {
			root.width = root.item.width
			root.height = root.item.height
		}
	}
}
