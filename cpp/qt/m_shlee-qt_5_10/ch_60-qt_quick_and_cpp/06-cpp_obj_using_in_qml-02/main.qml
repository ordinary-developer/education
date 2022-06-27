import QtQuick 2.8
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.1
import com.myinc.Calculation 1.0

ApplicationWindow {
	title: "Factorial  Calculation"
	width: 250
	height: 40
	visible: true
	
	Calculation {
		input: sbx.value
		onResultValueChanged: txt.text = "Result:" + result
	}
	RowLayout {
		SpinBox {
			id: sbx
			value: 0
		}
		Text {
			id: txt
		}
	}
}
