#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Ellipse.h"


int main(int argc, char ** argv) {
	QGuiApplication app{ argc, argv };
	
	//QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGL);
	
	qmlRegisterType<Ellipse>("com.myinc.Ellipse", 1, 0, "Ellipse");
	
	QQmlApplicationEngine engine{};
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	
	return app.exec();
}
