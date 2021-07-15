#include <QReadWriteLock>
#include <QStack>
#include <QString>
class ThreadSafeStringStack {
public:
    void push(QString const & str) {        
        lock_.lockForWrite();    
        strStack_.push(str);
        lock_.unlock();
    }
    
    QString pop() {
        lock_.lockForWrite();    
        QString const & ret = (strStack_.empty() ? QString{} : strStack_.pop());
        lock_.unlock();
        
        return ret;
    }
    
    bool isEmpty() { 
        lock_.lockForRead();
        bool const ret = strStack_.isEmpty();
        lock_.unlock();
        
        return ret;
    }
    
private:
    QReadWriteLock lock_;
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
