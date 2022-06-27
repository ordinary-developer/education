import QtQuick 2.8
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import com.myinc.Calculation 1.0

ApplicationWindow {
	title: "Factorial  Calculation"
	width: 250
	height: 80
	visible: true
	
	Calculation {
		id: calc
	}
	
	ColumnLayout {
		anchors.fill: parent
		
		RowLayout {
			SpinBox {
				id: sbx
				value: 0
			}
			Text {
				text: "Result:" + calc.factorial(sbx.value)
			}
		}
		
		RowLayout {
			SpinBox {
				value: 0
				onValueChanged: calc.input = value
			}
			Text {
				text: "Result:" + calc.result
			}
		}
	}
}

