var component;

function createImageObject() {
	component = Qt.createComponent("dynamic-image.qml");
	if (component.status === Component.Ready || component.status === Component.Error) {
		finishCreation();
	}
	else {
		component.statusChanged.connect(finishCreation);
	}
}

function finishCreation() {
	if (component.status === Component.Ready) {
		var incubator = component.incubateObject(root, { "x": 100, "y": 100 });
		if (incubator.status === Component.Ready) {
			var image = incubator.object;
		}
		else {
			incubator.onStatusChanged = function(status) {
				if (status === Component.Ready) {
					var image = incubator.object;
				}
			};
		}
	}
}
