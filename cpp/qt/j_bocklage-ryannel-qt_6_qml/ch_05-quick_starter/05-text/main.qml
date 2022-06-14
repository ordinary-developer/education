import QtQuick 2.8

Rectangle {
	id: root
	width: 140; height: 240
	color: "white"
	
	Text {
		id: txt1
		x: 12; y: 12
		text: "The quick brown fox"
		color: "#303030"
		font.family: "Ubuntu"
		font.pixelSize: 28
	}
	
	Text {
		id: txt2
		x: 12; y: 50
		text: 'A very long text A very long text A very long text A very long text A very long text'
		elide: Text.ElideMiddle
		style: Text.Sunken
		styleColor: '#FF4444'
		verticalAlignment: Text.AlignTop
	}
}
