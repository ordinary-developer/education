import QtQuick 2.8

Rectangle {
    color: myColor
    width: 200
    height: 200

	Text {
		anchors.centerIn: parent
		text: myText
	}
	
	ListView {
		anchors.fill: parent
		model: myModel
		delegate: Text { text: model.display }
	}
	
	MouseArea {
		anchors.fill: parent
		onPressed: {
			myWidget.setWindowTitle("Hello from QML");
			myWidget.slotDisplayDialog();
		}
	}
}
