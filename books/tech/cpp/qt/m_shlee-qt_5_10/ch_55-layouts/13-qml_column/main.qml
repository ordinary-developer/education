import QtQuick 2.8
import QtQuick.Layouts 1.3

Item {
	width: 360
	height: 560
	
	Column {
		anchors.centerIn: parent
		spacing: 10
		
		Rectangle {
			width: 64; height: 64; color: "red"
		}
		
		Rectangle {
			width: 64; height: 64; color: "blue"
		}
		
		Rectangle {
			width: 64; height: 64; color: "green"
		}
	}
}
