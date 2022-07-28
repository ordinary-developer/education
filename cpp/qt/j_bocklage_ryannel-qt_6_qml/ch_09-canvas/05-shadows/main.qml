import QtQuick

Window {
	id: root
	
	visible: true
    width: 420
    height: 220
	
	Canvas {
		id: canvas
		
		width: 400; height: 200
		smooth: true
		
		onPaint: {
			var ctx = getContext('2d');
			
			ctx.strokeStyle = "#333"
			ctx.fillRect(0, 0, canvas.width, canvas.height);
			
			ctx.shadowColor = "#2ed5fa";
			ctx.shadowOffsetX = 2;
			ctx.shadowOffsetY = 2;
			ctx.shadowBlur = 10;
			
			ctx.font = 'bold 80px sans-serif';
			ctx.fillStyle = "#24d12e";
			ctx.fillText("Canvas!", 30, 180);
		}
	}
}
