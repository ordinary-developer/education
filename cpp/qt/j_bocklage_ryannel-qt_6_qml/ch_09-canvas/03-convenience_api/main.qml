import QtQuick

Window {
	id: root
	
	visible: true
    width: 222
    height: 220
	
	Canvas {
		id: canvasObj
		
		width: 120; height: 120
		
		onPaint: {
			var ctx = getContext("2d")
			
			ctx.fillStyle = 'green'
			ctx.strokeStyle = "blue"
			ctx.lineWidth = 4
			
			ctx.fillRect(20, 20, 80, 80);
			ctx.clearRect(30, 30, 60, 60);
			ctx.strokeRect(20, 20, 40, 40);
		}
	}
}
