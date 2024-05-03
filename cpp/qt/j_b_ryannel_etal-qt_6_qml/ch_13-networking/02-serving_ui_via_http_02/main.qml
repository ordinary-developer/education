import QtQuick

Window {
	id: mainRoot

	visible: true
	width: root.width; height: root.height
	
	Loader {
		id: root
		source: 'https://gist.github.com/jryannel/7983492/raw'
		onLoaded: {
			root.width = root.item.width
			root.height = root.item.height
		}
	}
}
