#include <QSemaphore>
#include <QStack>
#include <QString>
class ThreadSafeStringStack {
public:
    void push(QString const & str) {        
        sem_.acquire();
        strStack_.push(str);
        sem_.release();
    }
    
    QString pop() {
        sem_.acquire();
        QString const & ret = (strStack_.empty() ? QString{} : strStack_.pop());
        sem_.release();
        
        return ret;
    }
    
    bool isEmpty() const { return strStack_.isEmpty(); }
    
private:
    QSemaphore sem_{1};
    QStack<QString> strStack_;
};

static ThreadSafeStringStack localStack;


#include <QThread>
class MyThread : public QThread {
public:
    void run() {
        localStack.push("str");
    }
};


#include <QDebug>
int main([[maybe_unused]] int argc, [[maybe_unused]] char** argv) {
    MyThread t1{}, t2{};
    t1.start(); t2.start();
    
    t1.quit(); t2.quit();
    t1.wait(); t2.wait();
    
    while (not localStack.isEmpty()) 
        qDebug() << localStack.pop();
}
