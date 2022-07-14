#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/main.qml"_qs);

    QQmlComponent component(&engine, "qrc:/CustomItem.qml");
    QObject * object = component.create();
    QString retValue = "";
    QString msg = "Message From C++";
    QMetaObject::invokeMethod(object, "qmlMethod", Q_RETURN_ARG(QString, retValue), Q_ARG(QString, msg));
    qDebug() << "QML method returned: " << retValue;


    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    delete object;

    return app.exec();
}
