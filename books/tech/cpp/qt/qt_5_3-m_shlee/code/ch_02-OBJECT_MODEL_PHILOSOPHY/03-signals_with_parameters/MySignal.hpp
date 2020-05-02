#include <QtCore>

class MySignal : public QObject {
    Q_OBJECT

    signals:
        void sendString(const QString&);

    public:
        void sendSignal() {
            emit sendString("Informtion");
        }
};
