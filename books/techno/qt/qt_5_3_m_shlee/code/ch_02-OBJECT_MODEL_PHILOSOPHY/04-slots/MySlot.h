#include <QtCore>

class MySlot : public QObject {
    Q_OBJECT

    public:
        MySlot() { }

    public slots:
        void slot() {
            qDebug() << "I'm a slot";
        }
};
