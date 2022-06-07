import QtQuick 2.8

Canvas {
    id: canv
    width: 400
    height: 160
    onPaint: {
        var ctx = getContext("2d")
        ctx.fillStyle = "Black"
        ctx.fillRect(0, 0, canv.width, canv.height)
        
        ctx.strokeStyle = "Yellow"
        ctx.shadowColor = "Yellow"
        ctx.shadowOffsetY = 5
        ctx.shadowBlur = 5
        ctx.font = "48px Arial"
        ctx.fillStyle = "Yellow"
        ctx.fillText("Text with shadow!", 10, canv.height / 2);
    }
}