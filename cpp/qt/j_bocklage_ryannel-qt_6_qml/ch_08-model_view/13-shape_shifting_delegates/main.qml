import QtQuick
import QtQuick.Controls


ApplicationWindow {
	visible: true
	width: 300
	height: 480
	
	Rectangle {
		anchors.fill: parent
		gradient: Gradient {
			GradientStop { position: 0.0; color: "#4a4a4a" }
			GradientStop { position: 1.0; color: "#2b2b2b" }
		}
	}
	
	ListView {
		id: listView
		
		anchors.fill: parent
		
		delegate: detailsDelegate
		model: planets
	}
	
	ListModel {
		id: planets
		
		ListElement {
			name: "Mercury";
			imageSource: "qrc:/mercury.jpeg";
			facts: "Mercury is the smallest planet in the Solar System. It is the closest planet to the sun. It makes one trip around the Sun once every 87.969 days.";
		}
		
		ListElement {
			name: "Venus";
			imageSource: "qrc:/venus.jpeg";
			facts: "Venus is the second planet from the Sun. It is a terrestrial planet because it has a solid, rocky surface. The other terrestrial planets are Mercury, Earth and Mars. Astronomers have known Venus for thousands of years.";
		}
		
		ListElement {
			name: "Earth";
			imageSource: "qrc:/earth.jpeg";
			facts: "The Earth is the third planet from the Sun. It is one of the four terrestrial planets in our Solar System. This means most of its mass is solid. The other three are Mercury, Venus and Mars. The Earth is also called the Blue Planet, 'Planet Earth', and 'Terra'.";			
		}
		
		ListElement {
			name: "Mars";
			imageSource: "qrc:/mars.jpeg";
			facts: "Mars is the fourth planet from the Sun in the Solar System. Mars is dry, rocky and cold. It is home to the largest volcano in the Solar System. Mars is named after the mythological Roman god of war because it is a red planet, which signifies the colour of blood.";
		}
	}
	
	Component {
		id: detailsDelegate
		
		Item {
			id: wrapper
			
			required property string name
			required property string imageSource
			required property string facts
			
			width: listView.width
			height: 30
			
			Rectangle {
				anchors.left: parent.left
				anchors.right: parent.right
				anchors.top: parent.top
				
				height: 30
				
				color: "#333"
				border.color: Qt.lighter(color, 1.2)
				Text {
					anchors.left: parent.left
					anchors.verticalCenter: parent.verticalCenter
					anchors.leftMargin: 4
					
					font.pixelSize: parent.height - 4
					color: '#fff'
					
					text: wrapper.name
				}
			}
			
			Rectangle {
				id: image
				
				width: 26
				height: 26
				
				anchors.right: parent.right
				anchors.top: parent.top
				anchors.rightMargin: 2
				anchors.topMargin: 2
				
				color: "black"
				
				Image {
					anchors.fill: parent
					fillMode: Image.PreserveAspectFit
					source: wrapper.imageSource
				}
			}
			
			MouseArea {
				anchors.fill: parent
				onClicked: parent.state = "expanded"
			}
			
			Item {
				id: factsView
				
				anchors.top: image.bottom
				anchors.left: parent.left
				anchors.right: parent.right
				anchors.bottom: parent.bottom
				
				opacity: 0
				
				Rectangle {
					anchors.fill: parent
					
					gradient: Gradient {
						GradientStop { position: 0.0; color: "#fed958" }
						GradientStop { position: 1.0; color: "#fecc2f" }
					}
					border.color: '#000000'
					border.width: 2
					
					Text {
						anchors.fill: parent
						anchors.margins: 5
						
						clip: true
						wrapMode: Text.WordWrap
						color: '#1f1f21'
						
						font.pixelSize: 12
						
						text: wrapper.facts
					}
				}
			}
			
			Rectangle {
				id: closeButton
				
				anchors.right: parent.right
				anchors.top: parent.top
				anchors.rightMargin: 2
				anchors.topMargin: 2
				
				width: 26
				height: 26
				
				color: "#157efb"
				border.color: Qt.lighter(color, 1.1)
				
				opacity: 0
				
				MouseArea {
					anchors.fill: parent
					onClicked: wrapper.state = ""
				}
			}
			
			states: [
				State {
					name: "expanded"
					
					PropertyChanges { target: wrapper; height: ListView.height }
					PropertyChanges { target: image; width: listView.width; height: listView.width; anchors.rightMargin: 0; anchors.topMargin: 30 }
					PropertyChanges { target: factsView; opacity: 1 }
					PropertyChanges { target: closeButton; opacity: 1 }
					PropertyChanges { target: wrapper.ListView.view; contentY: wrapper.y; interactive: false }
				}
			]
			
			transitions: [
				Transition {
					NumberAnimation {
						duration: 200;
						properties: "height,width,anchors.rightMargin,anchors.topMargin, opacity, contentY"
					}
				}
			]
		}
	}
}
