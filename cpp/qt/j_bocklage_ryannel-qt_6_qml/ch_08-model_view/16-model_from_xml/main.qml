import QtQuick
import QtQuick.Controls
import QtQml.XmlListModel


Window {
	id: root
	
	visible: true
    width: 320
    height: 500
	
	Background {
		width: 300
		height: 480
		
		Component {
			id: imageDelegate
			
			Box {
				id: wrapper
				
				required property string title
				required property string imageSource
				
				width: listView.width
				height: 220
				color: '#333'
				
				Column {
					Text {
						text: wrapper.title
						color: '#e0e0e0'
					}
					Image {
						height: 200
						fillMode: Image.PreserveAspectCrop
						source: wrapper.imageSource
					}
				}
			}
		}
		
		XmlListModel {
			id: imageModel
			
			source: "https://www.nasa.gov/rss/dyn/image_of_the_day.rss"
			query: "/rss/channel/item"
			
			XmlListModelRole { name: "title"; elementName: "title" }
			XmlListModelRole { name: "imageSource"; elementName: "enclosure"; attributeName: "url"; }
		}
		
		ListView {
			id: listView
			anchors.fill: parent
			model: imageModel
			delegate: imageDelegate
		}
	}
}
