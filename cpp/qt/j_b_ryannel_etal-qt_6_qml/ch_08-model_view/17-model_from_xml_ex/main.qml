import QtQuick

Window {
	id: root
	
	visible: true
    width: 320
    height: 500
	
	Loader {
		id: loader
		
		focus: true
		
		source: "Images.qml"
		
		onLoaded: {
			// qmllint disable
			setSize(loader.item.width, loader.item.height);
			shootWithDelay(3000);
			// qmllint enable
		}
	}
}
