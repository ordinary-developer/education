#include <QObject>
#include <QDebug>

int main() {
    QObject* pobj1 = new QObject;
    QObject* pobj2 = new QObject(pobj1);
    QObject* pobj4 = new QObject(pobj2);
    QObject* pobj3 = new QObject(pobj1);
    pobj2->setObjectName("the first child of pobj1");
    pobj3->setObjectName("the second child of pobj1");
    pobj4->setObjectName("the first child of pobj2");

    for (QObject* pobj = pobj4; pobj; pobj = pobj->parent()) {
        qDebug() << pobj->objectName();
    }

    QObject* pobj =
        pobj1->findChild<QObject*>("the first child of pobj2");
    QList<QObject*> plist1 = 
        pobj1->findChildren<QObject*>(QRegExp("th*"));
    QList<QObject*> plist2 =
        pobj1->findChildren<QObject*>();

    pobj1->dumpObjectInfo();
    pobj1->dumpObjectTree();

    qDebug() << pobj1->metaObject()->className();

    return 0;
}
