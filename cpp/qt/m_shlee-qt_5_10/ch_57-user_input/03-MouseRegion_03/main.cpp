#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlFileSelector>
#include <QQuickView>
#include <QDir>


int main(int argc, char** argv) {
	QGuiApplication app{ argc, argv };
	QQuickView view{};
	QFileInfo fileInfo{ app.applicationFilePath() };
	
	app.setApplicationName(fileInfo.baseName());
	
	view.connect(view.engine(), SIGNAL(quit()), &app, SLOT(quit()));
	new QQmlFileSelector(view.engine(), &view);
	
	view.setSource(QUrl{"qrc:/main.qml"});
	view.setResizeMode(QQuickView::SizeRootObjectToView);
	view.show();
	
	return app.exec();
}
