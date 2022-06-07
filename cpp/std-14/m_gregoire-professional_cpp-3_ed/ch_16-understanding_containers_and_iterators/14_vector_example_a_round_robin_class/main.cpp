#include "RoundRobin.hpp"

#include <stdexcept>
#include <iostream>
#include <string>


class Process {
    public:
        Process(const std::string& name) : mName(name) { }

        void doWorkDuringTimeSlice() {
            std::cout << "Process " << mName
                      << " performing work during time slice." << std::endl;
        }

        bool operator == (const Process& rhs) {
            return mName == rhs.mName;
        }
    private:
        std::string mName;
};

class Scheduler {
    public:
        Scheduler(const std::vector<Process>& processes);
        void scheduleTimeSlice();
        void removeProcess(const Process& process);
    private:
        RoundRobin<Process> rr;
};

Scheduler::Scheduler(const std::vector<Process>& processes) {
    for (auto& process : processes) {
        rr.add(process);
    }
}

void Scheduler::scheduleTimeSlice() {
    try {
        rr.getNext().doWorkDuringTimeSlice();
    }
    catch (const std::out_of_range&) {
        std::cerr << "No more processes to schedule." << std::endl;
    }
}

void Scheduler::removeProcess(const Process& process) {
    rr.remove(process);
}

auto main() -> int {
    std::vector<Process> processes = { Process("1"), Process("2"), Process("3") };

    Scheduler sched(processes);

    for (int i = 0; i < 4; ++i) {
        sched.scheduleTimeSlice();
    }

    sched.removeProcess(processes[1]);
    std::cout << "Removed second process" << std::endl;

    for (int i = 0; i < 4; ++i) {
        sched.scheduleTimeSlice();
    }

    return 0;
}
