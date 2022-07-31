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
			var ctx = getContext("2d");
			ctx.globalCompositeOperation = "xor";
			ctx.fillStyle = "#33a9ff";
			
			for (var i = 0; i < 40; i++) {
				ctx.beginPath();
				ctx.arc(Math.random() * 400, Math.random() * 200, 20, 0, 2 * Math.PI);
				ctx.closePath()
				ctx.fill();
			}
		}
	}
}
