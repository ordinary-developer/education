#include <QtCore>

class MySignal : public QObject {
    Q_OBJECT
    
    signals:
        void doIt();

    public:
        void sendSignal() {
            emit doIt();
        }
};
