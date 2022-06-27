#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "Calculation.h"


int main(int argc, char ** argv) {
	QGuiApplication app{ argc, argv };
	
	//QQuickWindow::setGraphicsApi(QSGRendererInterface::OpenGL);
	
	qmlRegisterType<Calculation>("com.myinc.Calculation", 1, 0, "Calculation");
	
	QQmlApplicationEngine engine{};
	engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
	
	return app.exec();
}
