import QtQuick
import "create-component.js" as ImageCreator

Window {
	id: mainRoot

	visible: true
	width: root.width; height: root.height
	
	Rectangle {
		id: root
		
		width: 1024
		height: 600
		
		Component.onCompleted: ImageCreator.createImageObject();
    }
}
