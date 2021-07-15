#include <QMutex>
#include <QMutexLocker>
#include <QStack>
#include <QString>
class ThreadSafeStringStack {
public:
    void push(QString const & str) {
        mut_.lock();
        strStack_.push(str);
        mut_.unlock();
    }
    
    QString pop() {
        QMutexLocker locker{&mut_};
        return strStack_.empty() ? QString{} : strStack_.pop();
    }
    
    bool isEmpty() const { return strStack_.isEmpty(); }
    
private:
    QMutex mut_;
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
