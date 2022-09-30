#pragma once

#include <thread>
#include <mutex>
#include <condition_variable>
#include <atomic>
#include <queue>
#include <string>


class Logger { 
    public:
        Logger(); 
        virtual ~Logger();
        Logger(Logger const& src) = delete;
        Logger& operator=(Logger const& rhs) = delete;

        void log(std::string const& entry);

    private:
        void processEntries();

        std::atomic<bool> exit_;
        std::thread thread_;
        std::queue<std::string> queue_;
        std::condition_variable conditionVar_;
        std::mutex mutex_;
};

