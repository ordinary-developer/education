import QtQuick

BrightSquare {
    id: root

    width: 800
    height: 680

    DarkSquare {
        id: container
        width: 800
        height: 480
        property int marginTop: 16
        property int marginRight: 32
        property int marginBottom: marginTop
        property int marginLeft: marginRight

        property int columns: 12
        property int rows: 8
        property int spacing: 12

        property int cellWidth:
          (width - marginLeft - marginRight - (columns - 1) * spacing) / columns
        property int cellHeight:
          (height - marginTop - marginBottom - (rows - 1) * spacing) / rows

        //property int cellWidth: 64
        //property int cellHeight: 64

        Grid {
            anchors.fill: parent

            anchors.topMargin: parent.marginTop
            anchors.rightMargin: parent.marginRight
            anchors.bottomMargin: parent.marginBottom
            anchors.leftMargin: parent.marginLeft
            spacing: parent.spacing
            columns: parent.columns

            Repeater {
                model: container.columns * container.rows

                RedSquare {
                    width: container.cellWidth
                    height: container.cellHeight
                }
            }
        }

        Component.onCompleted: {
            print('width = ', cellWidth)
            print('cellHeight = ', cellHeight)
        }
    }
}
