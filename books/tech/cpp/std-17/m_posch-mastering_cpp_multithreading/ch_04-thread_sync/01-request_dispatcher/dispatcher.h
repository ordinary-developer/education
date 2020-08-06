#pragma once

#include <queue>
#include <mutex>
#include <thread>
#include <vector>

class AbstractRequest;
class Worker;

class Dispatcher {
    public:
        static bool init(int workers);
        static bool stop();
        static void addRequest(AbstractRequest* request);
        static bool addWorker(Worker* worker);

    private:
        static std::queue<AbstractRequest*> requests_;
        static std::queue<Worker*> workers_;

        static std::mutex requestMutex_;
        static std::mutex workerMutex_;

        static std::vector<Worker*> allWorkers_;
        static std::vector<std::thread*> threads_;
};

