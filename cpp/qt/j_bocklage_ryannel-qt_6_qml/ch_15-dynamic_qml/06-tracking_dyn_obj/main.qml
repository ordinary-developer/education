import QtQuick
import QtQml.XmlListModel
import "create-object.js" as CreateObject

Window {
	id: mainRoot

	visible: true
	width: root.width; height: root.height
	
	Rectangle {
		id: root
		
		width: 1024
		height: 600
		
		ListModel {
			id: objectsModel
		}
		
		function addUfo() {
			CreateObject.create("ufo.qml", root, itemAdded);
		}
		
		function addRocket() {
			CreateObject.create("rocket.qml", root, itemAdded);
		}
		
		function itemAdded(obj, source) {
			objectsModel.append({"obj": obj, "source": source});
		}
		
		function clearItems() {
			while (objectsModel.count > 0) {
				objectsModel.get(0).obj.destroy();
				objectsModel.remove(0);
			}
		}
		
		function serialize() {
			var res = "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n<scene>\n";
			
			for (var ii = 0; ii < objectsModel.count; ++ii) {
				var i = objectModel.get(ii);
				res += "  <item>\n    <source>" + i.source + "</source>\n    <x>" + i.obj.x + "</x>\n    <y>" + i.obj.y + "</y>\n  </item>\n";
			}
			
			res += "</scene>";
			
			return res;
		}
		
		XmlListModel {
			id: xmlModel
			query: "/scene/item"
			XmlListModelRole { name: "source"; elementName: "source" }
			XmlListModelRole { name: "x"; elementName: "x" }
			XmlListModelRole { name: "y"; elementName: "y" }
		}
		
		function deserialize() {
			dsIndex = 0;
			CreateObject.create(xmlModel.get(dsIndex).source, root, dsItemAdded);
		}
		
		function dsItemAdded(obj, source) {
			itemAdded(obj, source);
			obj.x = xmlModel.get(dsIndex).x;
			obj.y = xmlModel.get(dsIndex).y;
			
			dsIndex++;
			
			if (dsIndex < xmlModel.count) {
				CreateObject.create(xmlModel.get(dsIndex).source, root, dsItemAdded);
			}
		}
		
		property int dsIndex;
		
		Column {
			anchors.left: parent.left
			anchors.top: parent.top
			anchors.topMargin: 10
			
			spacing: 10
			
			width: 100
			
			Image {
				anchors.horizontalCenter: parent.horizontalCenter
				source: "ufo.png"
				
				MouseArea {
					anchors.fill: parent
					onClicked: root.addUfo();
				}
			}
			
			Image {
				anchors.horizontalCenter: parent.horizontalCenter
				source: "rocket.png"
				
				MouseArea {
					anchors.fill: parent
					onClicked: root.addRocket();
				}
			}
			
			Rectangle {
				anchors.horizontalCenter: parent.horizontalCenter
				
				width: 100
				height: 40
				
				color: "#53d769"
				
				MouseArea {
					anchors.fill: parent
					onClicked: {
						xmlModel.xml = root.serialize();
						root.clearItems();
					}
				}
			}
			
			Rectangle {
				anchors.horizontalCenter: parent.horizontalCenter
				
				width: 100
				height: 40
				
				color: "#fed958"
				
				MouseArea {
					anchors.fill: parent
					onClicked: root.deserialize()
				}
			}
		}
    }
}
