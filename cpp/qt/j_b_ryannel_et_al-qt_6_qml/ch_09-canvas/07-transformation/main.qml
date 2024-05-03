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
			var ctx = getContext("2d")
			
			ctx.lineWidth = 4
			ctx.strokeStyle = "blue"
			
			ctx.translate(root.width / 2, root.height / 2)
			
			ctx.beginPath()
			ctx.rect(-20, -20, 40, 40)
			ctx.stroke()
			
			ctx.rotate(Math.PI / 4)
			ctx.strokeStyle = "green"
			
			ctx.beginPath()
			ctx.rect(-20, -20, 40, 40)
			ctx.stroke()
		}
	}
}
