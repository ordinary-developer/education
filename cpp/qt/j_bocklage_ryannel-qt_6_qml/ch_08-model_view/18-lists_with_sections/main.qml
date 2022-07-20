import QtQuick

Window {
	id: root
	
	visible: true
    width: 300
    height: 290
	
	ListView {
		anchors.fill: parent
		anchors.margins: 20
		
		clip: true
		
		model: spaceMen
		
		delegate: spaceManDelegate
		
		section.property: "nation"
		section.delegate: sectionDelegate
	}
	
	Component {
		id: spaceManDelegate
		
		Item {
			id: spaceManWrapper
			
			required property string name
			width: ListView.view.width
			height: 20
			Text {
				anchors.left: parent.left
				anchors.verticalCenter: parent.verticalCenter
				anchors.leftMargin: 8
				font.pixelSize: 12
				text: spaceManWrapper.name
				color: '#1f1f1f'
			}
		}
	}
	
	Component {
		id: sectionDelegate
		
		BlueBox {
			id: sectionWrapper
			required property string section
			width: ListView.view ? ListView.view.width : 0
			height: 20
			text: sectionWrapper.section
			fontColor: '#e0e0e0'
		}
	}
	
	ListModel {
		id: spaceMen
		
		ListElement { name: "Abdul Ahad Mohmand"; nation: "Afganistan"; }
		ListElement { name: "Marcos Pontes"; nation: "Brazil"; }
        ListElement { name: "Alexandar Panayotov Alexandrov"; nation: "Bulgaria"; }
        ListElement { name: "Georgi Ivanov"; nation: "Bulgaria"; }
        ListElement { name: "Roberta Bondar"; nation: "Canada"; }
        ListElement { name: "Marc Garneau"; nation: "Canada"; }
        ListElement { name: "Chris Hadfield"; nation: "Canada"; }
        ListElement { name: "Guy Laliberte"; nation: "Canada"; }
        ListElement { name: "Steven MacLean"; nation: "Canada"; }
        ListElement { name: "Julie Payette"; nation: "Canada"; }
        ListElement { name: "Robert Thirsk"; nation: "Canada"; }
        ListElement { name: "Bjarni Tryggvason"; nation: "Canada"; }
        ListElement { name: "Dafydd Williams"; nation: "Canada"; }

	}
}
