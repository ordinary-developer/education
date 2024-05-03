import QtQuick
import QtQml.XmlListModel

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
			model: xmlModel
			delegate: Rectangle {
				id: delegate
				required property var model
				width: view.cellWidth
				height: view.cellHeight
				color: model.value
				Text {
					anchors.centerIn: parent
					text: delegate.model.name
				}
			}
		}
		
		XmlListModel {
			id: xmlModel
			source: "colors.xml"
			query: "/colors/color"
			XmlListModelRole { name: 'name'; elementName: 'name' }
			XmlListModelRole { name: 'value'; elementName: 'value' }
		}
	}
}
