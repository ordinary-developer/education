import QtQuick

Rectangle {
	id: root
	width: 150
	height: 250
	
	property color black: '#1f1f21'
	property color red: '#fc3d39'
	property color green: '#53d769'
	
	gradient: Gradient {
		GradientStop { position: 0.0; color: "#2ed5fa" }
		GradientStop { position: 1.0; color: "#2467ec" }
	}
	
	Rectangle {
		id: light1
		x: 25; y: 15
		width: 100; height: width
		radius: width / 2
		color: root.black
		border.color: Qt.lighter(color, 1.1)
	}
	
	Rectangle {
		id: light2
		x: 25; y: 135
		width: 100; height: width
		radius: width / 2
		color: root.black
		border.color: Qt.lighter(color, 1.1)
	}
	
	state: "stop"
	
	states: [
		State {
			name: "stop"
			PropertyChanges { target: light1; color: root.red }
			PropertyChanges { target: light2; color: root.black }
		},
		State {
			name: "go"
			PropertyChanges { target: light1; color: root.black }
			PropertyChanges { target: light2; color: root.green }
		}
	]
	
	MouseArea {
		anchors.fill: parent
		onClicked: parent.state = (parent.state == "stop" ? "go" : "stop")
	}
	
	transitions: [
		Transition {
			from: "stop"; to: "go"
			ColorAnimation { target: light1; properties: "color"; duration: 2000 }
			ColorAnimation { target: light2; properties: "color"; duration: 2000 }
		}
	]
	
}