import QtQuick

Window {
	id: root

	visible: true
	width: 820; height: 470
	
	Canvas {
		id: canvas
		width: 800; height: 450
		
		property real hue: 0
		property real lastX: width * Math.random()
		property real lastY: height * Math.random()
		
		property bool requestLine: false
		property bool requestBlank: false
		
		Timer {
			id: lineTimer
			interval: 40
			repeat: true
			triggeredOnStart: true
			onTriggered: {
				canvas.requestLine = true;
				canvas.requestPaint();
			}
		}
		
		Timer {
			id: blankTimer
			interval: 50
			repeat: true
			triggeredOnStart: true
			onTriggered: {
				canvas.requestBlank = true;
				canvas.requestPaint();
			}
		}
		
		onPaint: {
			var context = getContext('2d');
			
			if (requestLine) {
				line(context);
				requestLine = false;
			}
			
			if (requestBlank) {
				blank(context);
				requestBlank = false;
			}
		}
		
		function line(context) {
			context.save();
			
			context.translate(canvas.width / 2, canvas.height / 2);
			context.scale(0.9, 0.9);
			context.translate(-canvas.width / 2, -canvas.height / 2);
			
			context.beginPath();
			
			context.lineWidth = 5 + Math.random() * 10
			
			context.moveTo(lastX, lastY)
			lastX = canvas.width * Math.random()
			lastY = canvas.height * Math.random()
			context.bezierCurveTo(
				canvas.width * Math.random(),
				canvas.height * Math.random(),
				canvas.width * Math.random(),
				canvas.height * Math.random(),
				lastX, lastY);
			
			hue += Math.random() * 0.1;
			if (hue > 1.0) {
				hue -= 1;
			}
			context.strokeStyle = Qt.hsla(hue, 0.5, 0.5, 1.0);
			context.shadowColor = 'white';
			context.shadowBlue = 10;
			
			context.stroke();
			
			context.restore();
		}
		
		function blank(context) {
			context.fillStyle = Qt.rgba(0, 0, 0, 0.1);
			context.fillRect(0, 0, canvas.width, canvas.height);
		}
		
		Component.onCompleted: {
			lineTimer.start();
			blankTimer.start();
		}
	}
}
