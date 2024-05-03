import QtQuick
import QtQuick.Controls

Window {
	id: mainRoot

	visible: true
	width: root.width; height: root.height
	
	Rectangle {
		id: root
		
		width: 1024
		height: 600
		
		function countDown() {
			for (var i = 0; i < 10; i++) {
				console.log('index: ' + i);
			}
		}
		
		function countDown2() {
			var i = 10;
			while (i > 0) {
				i--;
				console.log('index: ' + i);
			}
		}
		
		function getAge(name) {
			switch(name) {
				case "father":
					return 58;
				case "mother":
					return 56;
			}
			
			return undefined;
		}
		
		function doIt() {
			var a = [];
			a.push(10);
			a.push("Monkey");
			console.log(a.length);
			console.log(a[0]);
			console.log(a[1]);
			console.log(a[2]);
			a[99] = "String";
			console.log(a.length);
			console.log(a[98]);
		}
		
		function runJS() {
			console.log("Your JS code goes here");
		}
		
		Component.onCompleted: {
			countDown();
			countDown2();
			
			console.log(getAge("father"));
			console.log(getAge("mother"));
			console.log(getAge("FATHER"));
			console.log(getAge("MOTHER"));
			console.log(getAge("nobody"));
			
			doIt();
			
			runJS();
		}
    }
}
