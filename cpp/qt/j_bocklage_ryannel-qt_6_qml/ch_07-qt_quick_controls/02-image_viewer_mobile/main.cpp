#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>

int main(int argc, char * argv[]) {
	QGuiApplication app{ argc, argv };
	
	QQmlApplicationEngine engine{};
	QQuickStyle::setStyle("Material");
	engine.load(QUrl{QStringLiteral("qrc:/main.qml")});
	if (engine.rootObjects().isEmpty())
		return -1;
	
	return app.exec();
}
