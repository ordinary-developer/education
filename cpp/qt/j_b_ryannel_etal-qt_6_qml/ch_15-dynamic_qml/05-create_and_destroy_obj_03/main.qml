import QtQuick

Window {
	id: mainRoot

	visible: true
	width: root.width; height: root.height
	
	Rectangle {
		id: root
		
		width: 1024
		height: 600
		
		function createItem() {
			Qt.createQmlObject(
				"import QtQuick; Rectangle { x: 100; y: 100; width: 100; height: 100; color: \"blue\" }", root, "dynamicItem");
		}
		
		Component.onCompleted: root.createItem();
    }
}
