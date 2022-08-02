import QtQuick

Window {
	id: root

	visible: true
	width: 620
	height: 220

	Canvas {
		id: canvas
		
		width: 600; height: 200
		smooth: true
		
		property var operation : [
			'source-over', 'source-in', 'source-over',
			'source-atop', 'destination-over', 'destination-in',
			'destination-out', 'destination-atop', 'lighter',
			'copy', 'xor', 'qt-clear', 'qt-destination',
			'qt-multiply', 'qt-screen', 'qt-overlay', 'qt-darken',
			'qt-lighten', 'qt-color-dodge', 'qt-color-burn',
			'qt-hard-light', 'qt-soft-light', 'qt-difference',
			'qt-exclusion'
        ]
		
		onPaint: {
			var ctx = getContext('2d')
			
			for (var i = 0; i < operation.length; i++) {
				var dx = Math.floor(i % 6) * 100
				var dy = Math.floor(i / 6) * 100
				
				ctx.save()
				ctx.fillStyle = '#33a9ff'
				ctx.fillRect(10 + dx, 10 + dy, 60, 60)
				ctx.globalCompositeOperation = canvas.operation[i]
				ctx.fillStyle = '#ff33a9'
				ctx.globalAlpha = 0.75
				
				ctx.beginPath()
				ctx.arc(60 + dx, 60 + dy, 30, 0, 2 * Math.PI)
				ctx.closePath()
				ctx.fill()
				
				ctx.restore()
			}
		}
	}
}
