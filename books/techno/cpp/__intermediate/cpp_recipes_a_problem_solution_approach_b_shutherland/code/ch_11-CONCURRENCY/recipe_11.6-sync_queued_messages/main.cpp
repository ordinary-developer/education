#include <cassert>
#include <future>
#include <iostream>
#include <vector>

class RunningTotal {
    private:
        int m_Value{ 0 };
        bool m_Finished{ false };

    public:
        RunningTotal& operator+=(int value) {
            m_Value += value;
            return *this;
        }

        RunningTotal& operator-=(int value) {
            m_Value -= value;
            return *this;
        }

        RunningTotal& Finish() {
            m_Finished = true;
            return *this;
        }

        int operator *() const throw(int)
        {
            if (not m_Finished)
                throw m_Value;
            return m_Value;
        }
};

template <typename T>
class MessageQueue {
    private:
        using Queue = std::vector<T>;
        using QueueIterator = typename Queue::iterator;

        Queue m_A;
        Queue m_B;

        Queue* m_Producer{ &m_A };
        Queue* m_Consumer{ &m_B };

        QueueIterator m_ConsumerIterator{ m_B.end() };

        std::condition_variable& m_MessageCondition;
        std::condition_variable m_ConsumptionFinished;

        std::mutex m_MutexProducer;
        std::mutex m_MutexConsumer;

        unsigned int m_SwapCount{ 0 };

    public:
        MessageQueue(std::condition_variable& messageCondition)
            : m_MessageCondition{ messageCondition } { }

        unsigned int GetCount() const {
            return m_SwapCount;
        }

        void Add(T&& operation) {
            std::unique_lock<std::mutex> lock{ m_MutexProducer };
            m_Producer->insert(m_Producer->end(), std::move(operation));
        }

        void BeginConsumption() {
            m_MutexConsumer.lock();
        }

        T Consume() {
            T operation{};

            if (m_Consumer->size() > 0) {
                operation = *m_ConsumerIterator;
                m_ConsumerIterator = m_Consumer->erase(m_ConsumerIterator);
                assert(m_ConsumerIterator == m_Consumer->begin());
            }

            return operation;
        }

        void EndConsumption() {
            assert(m_Consumer->size() == 0);
            m_MutexConsumer.unlock();
            m_ConsumptionFinished.notify_all();
        }

        unsigned int Swap() {
            std::unique_lock<std::mutex> lockB{ m_MutexConsumer };
            m_ConsumptionFinished.wait(lockB,
                                       [this]() { 
                                         return m_Consumer->size() == 0;
                                       });
            std::unique_lock<std::mutex> lockA { m_MutexProducer };

            Queue* temp{ m_Producer };
            m_Producer = m_Consumer;
            m_Consumer = temp;

            m_ConsumerIterator = m_Consumer->begin();
            m_MessageCondition.notify_all();

            return m_SwapCount++;
        }
};

using RunningTotalOperation = std::function<RunningTotal&()>;
using RunningTotalMessageQueue = MessageQueue<RunningTotalOperation>;

int Task(std::reference_wrapper<std::mutex> messageQueueMutex,
         std::reference_wrapper<std::condition_variable> messageCondition,
         std::reference_wrapper<RunningTotalMessageQueue> messageQueueRef)
{
    int result{0};

    RunningTotalMessageQueue& messageQueue = messageQueueRef.get();
    unsigned int currentSwapCount{ 0 };

    bool finished{ false };
    while (not finished) {
        std::unique_lock<std::mutex> lock{ messageQueueMutex.get() };
        messageCondition.get().wait(lock,
                                    [&messageQueue, &currentSwapCount]() {
                                        return currentSwapCount =!
                                            messageQueue.GetCount();
                                    });

        messageQueue.BeginConsumption();
        currentSwapCount = messageQueue.GetCount();

        while (RunningTotalOperation operation{ messageQueue.Consume() })
        {
            RunningTotal& runningTotal = operation();
            try {
                result = *runningTotal;
                finished = true;
                break;
            }
            catch (int param) { std::cout << "Total not yet finished, current is: "
                                          << param << std::endl; }
        }
        messageQueue.EndConsumption();
    }

    return result;
}

int main() {
    RunningTotal runningTotal{};

    std::mutex messageQueueMutex{};
    std::condition_variable messageQueueCondition{};
    RunningTotalMessageQueue messageQueue(messageQueueCondition);

    auto myFuture = std::async(std::launch::async,
                               Task,
                               std::ref(messageQueueMutex),
                               std::ref(messageQueueCondition),
                               std::ref(messageQueue));

    messageQueue.Add(std::bind(&RunningTotal::operator+=, &runningTotal, 3));
    messageQueue.Swap();

    messageQueue.Add(std::bind(&RunningTotal::operator-=, &runningTotal, 100));
    messageQueue.Add(std::bind(&RunningTotal::operator+=, &runningTotal, 100000));
    messageQueue.Add(std::bind(&RunningTotal::operator-=, &runningTotal, 256));
    messageQueue.Swap();

    messageQueue.Add(std::bind(&RunningTotal::operator-=, &runningTotal, 100));
    messageQueue.Add(std::bind(&RunningTotal::operator+=, &runningTotal, 100000));
    messageQueue.Add(std::bind(&RunningTotal::operator-=, &runningTotal, 256));
    messageQueue.Swap();

    messageQueue.Add(std::bind(&RunningTotal::Finish, &runningTotal));
    messageQueue.Swap();

    std::cout << "The final total is: " << myFuture.get() << std::endl;

    return 0;
    
}
