import QtQuick 2.8

Rectangle {
	id: root
	width: 140; height: 240
	color: "white"
	
	Image {
		x: 12; y: 12
		source: "triangle_red.png"
	}
	
	Image {
		x: 12 + 64 + 12; y: 12
		height: 72 / 2
		source: "triangle_red.png"
		fillMode: Image.PreserveAspectCrop
		clip: true
	}
}
