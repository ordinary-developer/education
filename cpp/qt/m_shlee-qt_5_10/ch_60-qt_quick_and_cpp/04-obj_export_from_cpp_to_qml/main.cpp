#include <QtWidgets>
#include <QQuickWindow>
#include "MyWidget.h"

int main(int argc, char ** argv) {
	QApplication app{ argc, argv };
	
	QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGL); 

	MyWidget mw{};
	mw.show();
	
	return app.exec();
}
