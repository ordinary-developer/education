#include <QtWidgets>


class ProgressEvent : public QEvent {
private:
    int m_nValue;
    
public:
    enum { ProgressType = User + 1 };
    
    ProgressEvent() : QEvent{ static_cast<Type>(ProgressType) } {}
    
    void setValue(int n) { m_nValue = n; }
    int value() const { return m_nValue; }
};


class MyThread : public QThread {
private:
    QObject* m_pObjReceiver;
    
public:
    MyThread(QObject* pObjReceiver) : m_pObjReceiver{pObjReceiver} {}
    
    void run() {
        for (int i{0}; i <= 100; ++i) {
            usleep(100000);
            
            ProgressEvent* pEvent = new ProgressEvent{};
            pEvent->setValue(i);
            QApplication::postEvent(m_pObjReceiver, pEvent);
        }
    }
};


class MyProgressBar : public QProgressBar {
public:
    MyProgressBar(QWidget* parentWgt = nullptr) : QProgressBar{parentWgt} {}
    
    void customEvent(QEvent* pEvent) {
        if ((int)pEvent->type() == ProgressEvent::ProgressType) {
            setValue(((ProgressEvent*)(pEvent))->value());
        }
        QWidget::customEvent(pEvent);
    }
};


int main(int argc, char** argv) {
    QApplication app{argc, argv};
    
    MyProgressBar progressBar{};
    MyThread thread{&progressBar};
    
    progressBar.show();
    
    thread.start();
    
    return app.exec();
}
