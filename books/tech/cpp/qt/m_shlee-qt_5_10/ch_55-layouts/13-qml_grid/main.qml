import QtQuick 2.8
import QtQuick.Layouts 1.3

Item {
    width: 200
    height: 200
    
    Grid {
        rows: 2
        columns: 2
        anchors.centerIn: parent
        spacing: 10
        
        Rectangle { width: 64; height: 64; color: "red" }
        Rectangle { width: 64; height: 64; color: "blue" }
        Rectangle { width: 64; height: 64; color: "green" }
        Rectangle { width: 64; height: 64; color: "black" }
    }
}
