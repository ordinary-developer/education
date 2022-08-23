import QtQuick
import QtQuick.Controls
import QtQuick.Layouts
import QtQuick.Window
import "jsconsole.js" as Util

ApplicationWindow {
	id: root

	title: qsTr("JSConsole")
	width: 640
	height: 480
	visible: true
	
	menuBar: MenuBar {
		Menu {
			title: qsTr("File")
			MenuItem {
				text: qsTr("Exit")
				onTriggered: Qt.quit()
			}
		}
	}
	
	ColumnLayout {
		anchors.fill: parent
		anchors.margins: 9
		
		RowLayout {
			Layout.fillWidth: true
			TextField {
				id: input
				Layout.fillWidth: true
				focus: true
				onAccepted: {
					root.jsCall(input.text);
				}
			}
			
			Button {
				text: qsTr("Send")
				onClicked: {
					root.jsCall(input.text);
				}
			}
		}
		
		Item {
			Layout.fillWidth: true
			Layout.fillHeight: true
			
			Rectangle {
				anchors.fill: parent
				color: '#333'
				border.color: Qt.darker(color)
				opacity: 0.2
				radius: 2
			}
			
			ScrollView {
				id: scrollView
				anchors.fill: parent
				anchors.margins: 9
				
				ListView {
					id: resultView
					
					model: ListModel {
						id: outputModel
					}
					
					delegate: ColumnLayout {
						id: delegate
						required property var model
						
						Label {
							Layout.fillWidth: true
							color: 'green'
							text: "> " + delegate.model.expression
						}
						
						Label {
							Layout.fillWidth: true
							color: delegate.model.error === "" ? 'blue' : 'red'
							text: delegate.model.error === "" ? "" + delegate.model.result : delegate.model.error
						}
						
						Rectangle {
							height: 1
							Layout.fillWidth: true
							color: '#333'
							opacity: 0.2
						}
					}
				}
			}
		}
		
	}
	
	function jsCall(exp) {
		const data = Util.call(exp);
		
		outputModel.insert(0, data);
	}
}
