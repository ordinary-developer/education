#pragma once

#include "request.h"

#include <condition_variable>
#include <mutex>

class Worker {
    public:
        Worker() : 
            request_{ nullptr },
            cv_{}, mtx_{}, ulock_{ std::unique_lock<std::mutex>{mtx_} },
            running_{ true }, ready_{ false } 
        { }

        void setRequest(AbstractRequest* request) {
            request_ = request;
            ready_ = true;
        }
        
        void getCondition(std::condition_variable*& cv) {
            cv = &cv_;
        }

        void run();
        void stop();

    private:
        AbstractRequest* request_;

        std::condition_variable cv_;
        std::mutex mtx_;
        std::unique_lock<std::mutex> ulock_;

        bool running_; 
        bool ready_;
};


