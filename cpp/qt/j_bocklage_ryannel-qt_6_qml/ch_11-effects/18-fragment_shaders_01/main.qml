import QtQuick
import QtQuick.Particles

Window {
	id: main_root

	visible: true
	width: 500; height: 260	
	
	Rectangle {
		width: 480; height: 240
		color: '#1e1e1e'
		
		Grid {
			anchors.centerIn: parent
			spacing: 20
			rows: 2; columns: 4
			Image {
				id: sourceImage
				width: 80; height: width
				source: 'tulips.jpg'
			}
		}
	}
}
