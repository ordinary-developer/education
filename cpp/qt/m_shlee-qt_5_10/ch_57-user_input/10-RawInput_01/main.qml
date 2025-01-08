import QtQuick 2.8

Rectangle {
	width: 200
	height: 100
	Text {
		x: 20;
		y: 20;
		text: "Move this text<br>(use the cursor-keys)"
		horizontalAlignment: Text.AlignHCenter
		Keys.onLeftPressed: x -= 3
		Keys.onRightPressed: x += 3
		Keys.onDownPressed: y += 3
		Keys.onUpPressed: y -= 3
		focus: true
	}
}
