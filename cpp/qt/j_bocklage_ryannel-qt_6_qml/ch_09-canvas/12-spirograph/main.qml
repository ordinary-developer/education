import QtQuick

Window {
	id: root

	visible: true
	width: 320; height: 320
	
	Canvas {
		id: canvas
		width: 300; height: 300
		
		onPaint: {
			var ctx = getContext("2d");
			draw(ctx);
		}
		
		function draw(ctx) {
			ctx.fillRect(0, 0, 300, 300);
			for (var i = 0; i < 3; i++) {
				for (var j = 0; j < 3; j++) {
					ctx.save();
					ctx.strokeStyle = "#9CFF00";
					ctx.translate(20 + j * 50, 20 + i * 50);
					drawSpirograph(ctx, 20 * (j + 2) / (j + 1), -8 * (i + 3) / (i + 1), 10);
					ctx.restore();
				}
			}
		}
		
		function drawSpirograph(ctx, R, r, O) { 
			var x1 = R - O;
			var y1 = 0;
			var i = 1;
			
			ctx.beginPath();
			ctx.moveTo(x1, y1);
			do {
				if (i > 20000)
					break;
				
				var x2 = (R + r) * Math.cos(i * Math.PI / 72) - (r + O) * Math.cos(((R + r) / r) * (i * Math.PI / 72));
				var y2 = (R + r) * Math.sin(i * Math.PI / 72) - (r + O) * Math.sin(((R + r) / r) * (i * Math.PI / 72));
				ctx.lineTo(x2, y2);
				
				x1 = x2;
				y1 = y2;
				i++;
			} while (x2 != R - O && y2 != 0);
			ctx.stroke();
		}
	}
}
