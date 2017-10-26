#include "logger.hpp"

#include <iostream>
#include <fstream>


Logger::Logger() 
    : exit_{false}
{
    thread_ = std::thread{ &Logger::processEntries, this };
}

Logger::~Logger() {
    {
        std::unique_lock<std::mutex> lock{mutex_};
        exit_ = true;
        conditionVar_.notify_all();
    }
    thread_.join();
}

void Logger::log(std::string const& entry) {
    std::unique_lock<std::mutex> lock{ mutex_ };
    queue_.push(entry);
    conditionVar_.notify_all();
}

void Logger::processEntries() {
    std::ofstream fileToWrite("log.txt");
    if (fileToWrite.fail()) {
        std::cerr << "Failed to open logfile." << std::endl;
        return;
    }

    std::unique_lock<std::mutex> lock{ mutex_ };
    while (true) {
        if (not exit_) 
            conditionVar_.wait(lock);

        lock.unlock();
        while (true) {
            lock.lock();
            if (queue_.empty())
                break;
            else {
                fileToWrite << queue_.front() << std::endl;
                queue_.pop();
            }
            lock.unlock();
        }

        if (exit_)
            break;
    }
}

