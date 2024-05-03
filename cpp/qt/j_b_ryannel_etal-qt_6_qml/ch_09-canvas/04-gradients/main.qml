import QtQuick

Window {
	id: root

	visible: true
	width: 140
	height: 140

	Canvas {
		id: canvas
		
		width: 120; height: 120

		onPaint: {
			var ctx = getContext("2d")
			
			var gradient = ctx.createLinearGradient(100, 0, 100, 200)
			gradient.addColorStop(0, "blue")
			gradient.addColorStop(0.5, "lightsteelblue")
			ctx.fillStyle = gradient
			ctx.fillRect(50, 50, 100, 100)
		}
	}
}
