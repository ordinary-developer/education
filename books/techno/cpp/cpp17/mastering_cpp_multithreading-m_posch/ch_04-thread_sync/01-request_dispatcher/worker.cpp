#include "worker.h"
#include "dispatcher.h"

#include <chrono>

void Worker::run() {
    while (running_) {
        if (ready_) {
            ready_ = false;
            request_->process();
            request_->finish();
        }
        if (Dispatcher::addWorker(this)) {
            while (not ready_ and running_) {
                if (cv_.wait_for(ulock_, std::chrono::seconds(1)) == 
                        std::cv_status::timeout)
                { }
            }
        }
    }
}

void Worker::stop() {
    running_ = false;
}


