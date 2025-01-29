#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "ImageProvider.h"


int main(int argc, char ** argv) {
	QGuiApplication app{ argc, argv };
	
	//QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGL);
	
	QQmlApplicationEngine eng{};
	eng.addImageProvider(QLatin1String("brightness"), new ImageProvider);
	eng.load(QUrl(QStringLiteral("qrc:/main.qml")));
	
	return app.exec();
}
