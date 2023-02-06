#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "customobject.h"


int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url("qrc:/prj/main.qml");

    qmlRegisterType<CustomObject>("MyCustomObject", 1, 0, "CustomObject");

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
