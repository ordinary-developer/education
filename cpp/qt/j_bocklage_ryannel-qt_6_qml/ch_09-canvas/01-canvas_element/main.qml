import QtQuick

Window {
	id: root
	
	visible: true
    width: 222
    height: 220
	
	Canvas {
		id: canvasObj
		
		width: 200; height: 200
		
		onPaint: {
			var ctx = getContext("2d");
			
			ctx.lineWidth = 4;
			ctx.strokeStyle = "blue";
			ctx.fillStyle = "steelblue";
			
			ctx.beginPath();
			ctx.moveTo(50, 50);
			ctx.lineTo(150, 50);
			ctx.lineTo(150, 150);
			ctx.lineTo(50, 150);			
			ctx.closePath();
			
			ctx.fill();
			
			ctx.stroke()		
		}		
	}
}
