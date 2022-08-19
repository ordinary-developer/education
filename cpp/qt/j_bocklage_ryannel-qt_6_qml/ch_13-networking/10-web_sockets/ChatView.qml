import QtQuick

ListView {
	id: root
	width: 100
	height: 62
	
	model: ListModel {}
	
	function append(prefix, message) {
		model.append({ prefix: prefix, message: message });
	}
	
	delegate: Row {
		id: delegate
		
		required property var model
		property real cw: width / 24
		
		width: root.width
		height: 18
		
		Label {
			width: delegate.cw * 1
			height: parent.height
			text: delegate.model.prefix
		}
		
		Label {
			width: delegate.cw * 23
			height: parent.height
			text: delegate.model.message
		}
	}
}