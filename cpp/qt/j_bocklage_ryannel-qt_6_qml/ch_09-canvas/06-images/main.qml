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
			var ctx = getContext('2d')
			
			ctx.drawImage("ball.png", 10, 10)
			
			ctx.save()
			ctx.strokeStyle = '#ff2a68'
			
			ctx.beginPath()
			ctx.moveTo(110, 10)
			ctx.lineTo(155, 10)
			ctx.lineTo(135, 55)
			ctx.closePath()
			
			ctx.clip()
			ctx.drawImage('ball.png', 100, 10)
			
			ctx.stroke()
			ctx.restore()
		}
		
		Component.onCompleted: {
			loadImage("ball.png")
		}
	}
}
