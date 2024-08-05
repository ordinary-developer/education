// PROBLEMS
// - ABA problem
//   Comments from CppReference
//   > Due to the ABA problem, transient changes from 'old' (see the note 1 later) to antoher value
//   > and back to old might be missed, and not unblock
// - missed wakeups (?)

#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

std::vector<int> myVec{};

std::atomic_flag atomicFlag{};

void prepareWork() {
    myVec.insert(myVec.end(), { 0, 1, 0, 3 });
    std::cout << "Sender: Data prepared." << '\n';
    atomicFlag.test_and_set();
    atomicFlag.notify_one();
}

void completeWork() {
    std::cout << "Waiter: Waiting for data." << '\n';
    atomicFlag.wait(false);
    myVec[2] = 2;
    std::cout << "Waiter: Complete the work." << '\n';
    for (auto i : myVec)
        std::cout << i << " ";
    std::cout << '\n';
}

int main() {
    std::cout << '\n';
    
    std::thread t1(prepareWork);
    std::thread t2(completeWork);
    
    t1.join();
    t2.join();
    
    std::cout << '\n';
}
