import QtQuick

DarkSquare {
    id: root
    
    width: 400; height: 240
    
    Grid {
        anchors.fill: parent
        anchors.margins: 16
        spacing: 8
        columns: 4
        
        // M1>>
        GreenSquare {
            BlueSquare {
                width: 12
                anchors.fill: parent
                anchors.margins: 8
                text: '(1)'
            }
        }
        // <<M1
        
        // M2>>
        GreenSquare {
            BlueSquare {
                width: 48
                y: 8
                anchors.left: parent.left
                anchors.leftMargin: 8
                text: '(2)'
            }
        }
        // <<M2
        
        // M3>>
        GreenSquare {
            BlueSquare {
                width: 48
                anchors.left: parent.right
                text: '(3)'
            }
        }
        // <<M3
        
        EmptySquare {}
        
        // M4>>
        GreenSquare {
            BlueSquare {
                id: blue1
                width: 48; height: 24
                y: 8
                anchors.horizontalCenter: parent.horizontalCenter
            }
            
            BlueSquare {
                id: blue2
                width: 72; height: 24
                anchors.top: blue1.bottom
                anchors.topMargin: 4
                anchors.horizontalCenter: parent.horizontalCenter
                text: '(4)'
            }
        }
        // <<M4
        
        // M5>>
        GreenSquare {
            BlueSquare {
                width: 48
                anchors.centerIn: parent
                text: '(5)'
            }
        }
        // <<M5
        
        // M6>>
        GreenSquare {
            BlueSquare {
                width: 48
                anchors.horizontalCenter: parent.horizontalCenter
                anchors.horizontalCenterOffset: -12
                anchors.verticalCenter: parent.verticalCenter
                text: '(6)'
            }
        }
        // <<M6
    }
}