#include <QtWidgets>

class MyThread : public QThread {
Q_OBJECT

public:
    void run() {
        for (int i{0}; i <= 100; ++i) {
            usleep(100000);
            emit progress(i);
        }
    }
    
signals:
    void progress(int);
};


#include <QtWidgets>
int main(int argc, char** argv) {
    QApplication app{argc, argv};
    
    QProgressBar progressBar{};
    MyThread thread{};
    
    QObject::connect(&thread, static_cast<void (MyThread::*)(int)>(&MyThread::progress),
        &progressBar, static_cast<void (QProgressBar::*)(int)>(&QProgressBar::setValue));
        
    progressBar.show();
    
    thread.start();
    
    return app.exec();
}

#include "main.moc"
