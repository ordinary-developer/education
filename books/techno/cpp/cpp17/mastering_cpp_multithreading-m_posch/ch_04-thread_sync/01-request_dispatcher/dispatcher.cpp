#include "dispatcher.h"

#include "request.h"
#include "worker.h"

#include <iostream>

std::queue<AbstractRequest*> Dispatcher::requests_;
std::queue<Worker*> Dispatcher::workers_;

std::mutex Dispatcher::requestMutex_;
std::mutex Dispatcher::workerMutex_;

std::vector<Worker*> Dispatcher::allWorkers_;
std::vector<std::thread*> Dispatcher::threads_;


bool Dispatcher::init(int workers) {
    std::thread* t{ nullptr };
    Worker* w{ nullptr };

    for (int i{0}; i < workers; ++i) {
        w = new Worker;
        allWorkers_.push_back(w);
        t = new std::thread(&Worker::run, w);
        threads_.push_back(t);
    }

    return true;
}

bool Dispatcher::stop() {
    for (int i{0}; i < allWorkers_.size(); ++i) {
        allWorkers_[i]->stop();
    }

    std::cout << "Stopped workers.\n";
    for (int i{0}; i < threads_.size(); ++i) {
        threads_[i]->join();
        std::cout << "Joined threads.\n";
    }
}

void Dispatcher::addRequest(AbstractRequest* request) {
    workerMutex_.lock();
    if (not workers_.empty()) {
        Worker* worker = workers_.front();
        worker->setRequest(request);
        std::condition_variable* cv;
        worker->getCondition(cv);
        cv->notify_one();
        workers_.pop();
        workerMutex_.unlock();
    }
    else {
        workerMutex_.unlock();
        requestMutex_.lock();
        requests_.push(request);
        requestMutex_.unlock();
    }
}

bool Dispatcher::addWorker(Worker* worker) {
    bool wait = true;
    requestMutex_.lock();
    if (not requests_.empty()) {
        AbstractRequest* request = requests_.front();
        worker->setRequest(request);
        requests_.pop();
        wait = false;
        requestMutex_.unlock();
    }
    else {
        requestMutex_.unlock();
        workerMutex_.lock();
        workers_.push(worker);
        workerMutex_.unlock();
    }

    return wait;
}
