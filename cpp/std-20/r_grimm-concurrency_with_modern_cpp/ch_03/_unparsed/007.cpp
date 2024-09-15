#include <atomic>
#include <iostream>


int main() {
    std::atomic<long long> atomObj{2011};
    atomObj = 2014;
    long long nonAtomObj = atomObj;    
}
