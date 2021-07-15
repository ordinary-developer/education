#include <QMutex>
#include <QMutexLocker>
#include <QWaitCondition>
#include <QStack>
#include <QString>
class ThreadSafeStringStack {
public:
    void push(QString const & str) {
        QMutexLocker locker{&mut_};        
        strStack_.push(str);
    }
    
    QString pop() {
        QMutexLocker locker{&mut_};
        while (strStack_.empty()) {
            if (not waitCond_.wait(&mut_, 10000)) {
                return QString{};
            }
        }
        return (strStack_.empty() ? QString{} : strStack_.pop());
    }
    
    bool isEmpty() { 
        QMutexLocker locker{&mut_};
        return strStack_.empty();        
    }
    
private:
    QMutex mut_;
    QWaitCondition waitCond_;
    QStack<QString> strStack_;
};

static ThreadSafeStringStack localStack;


#include <QThread>
class MyThread : public QThread {
public:
    void run() {
        localStack.push("str1");
        usleep(100000);
        localStack.pop();
        localStack.push("str1");
        localStack.push("str2");
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
