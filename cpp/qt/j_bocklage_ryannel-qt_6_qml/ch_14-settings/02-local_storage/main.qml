import QtQuick
import QtQuick.LocalStorage 2.0


Window {
	id: mainRoot

	visible: true
	width: root.width; height: root.height
	
	Item {
		id: root
		width: 400
		height: 400
		
		Rectangle {
			id: crazy
			objectName: 'crazy'
			width: 100
			height: 100
			x: 50
			y: 50
			color: '#53d769'
			border.color: Qt.lighter(color, 1.1)
			
			Text {
				anchors.centerIn: parent
				text: Math.round(parent.x) + '/' + Math.round(parent.y)
			}
			MouseArea {
				anchors.fill: parent
				drag.target: parent
			}
		}
		
		property var db
		
		function initDatabase() {
			print('initDatabase()');
			db = LocalStorage.openDatabaseSync("CrazyBox", "1.0", "A box who remembers its position", 100000);
			db.transaction(function(tx) {
				print('... create table');
				tx.executeSql('CREATE TABLE IF NOT EXISTS data(name TEXT, value TEXT)');
			});
		}
		
		function storeData() {
			print('storeData()')
			if (!db) {
				return;
			}
			
			db.transaction(function(tx) {
				print('... check if a crazy object exists');
				var result = tx.executeSql('SELECT * FROM data WHERE name = "crazy"');
				
				var obj = { x: crazy.x, y: crazy.y }
				if (result.rows.length === 1) {
					print('... crazy exists, update it');
					result = tx.executeSql('UPDATE data SET value=? WHERE name="crazy"', [JSON.stringify(obj)]);
				}
				else {
					print('... crazy does not exists, create it');
					result = tx.executeSql('INSERT INTO data VALUES (?, ?)', ['crazy', JSON.stringify(obj)])
				}
			});
		}
		
		function readData() {
			print('readData()');
			if (!db) {
				return;
			}
			
			db.transaction(function(tx) {
				print('... read crazy object');
				const result = tx.executeSql('SELECT * FROM data WHERE name = "crazy"');
				if (result.rows.length === 1) {
					print('... update crazy geometry');
					const value = result.rows[0].value;
					
					const obj = JSON.parse(value);
					crazy.x = obj.x;
					crazy.y = obj.y;
				}
			});
		}
		
		Component.onCompleted: {
			initDatabase()
			readData()
		}
		
		Component.onDestruction: {
			storeData()
		}			
    }
}
