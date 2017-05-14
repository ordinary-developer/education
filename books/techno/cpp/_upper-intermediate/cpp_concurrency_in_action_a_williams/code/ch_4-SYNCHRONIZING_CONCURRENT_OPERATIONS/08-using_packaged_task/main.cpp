#include <deque>
#include <mutex>
#include <future>
#include <thread>
#include <utility>

std::mutex m;
std::deque<std::packaged_task<void()>> tasks;

#include <cstdlib>
#include <time.h>
bool gui_shutdown_message_received() { 
    srand(time(NULL));
    return ((double)rand() / (double)RAND_MAX) > 0.5;
}
void get_and_process_gui_message() { }

void gui_thread() {
    while (!gui_shutdown_message_received()) {
        get_and_process_gui_message();
        std::packaged_task<void()> task;
        {
            std::lock_guard<std::mutex> lk(m);
            if (tasks.empty()) {
                continue;
            }
            task = std::move(tasks.front());
            tasks.pop_front();
        }
        task();
    }
}

template <typename Func>
std::future<void> post_task_for_gui_thread(Func f) {
    std::packaged_task<void()> task(f);
    std::future<void> res = task.get_future();
    std::lock_guard<std::mutex> lk(m);
    tasks.push_back(std::move(task));
    return res;
}

#include <iostream>
int main() {
    post_task_for_gui_thread([]() {
        std::cout << "1-st task" << std::endl;
    });
    post_task_for_gui_thread([]() {
        std::cout << "2-nd task" << std::endl; 
    });

    std::thread gui_bg_thread(gui_thread);
    gui_bg_thread.join();

    return 0;
}
