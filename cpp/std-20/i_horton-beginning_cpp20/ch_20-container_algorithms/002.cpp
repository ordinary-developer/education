#include <iostream>
#include <queue>
#include <stack>

int main() {
    std::stack<int> stack;
    for (int i{}; i < 10; ++i)
        stack.push(i);

    std::cout << "The elements coming off the top of the stack: ";
    while (not stack.empty()) {
        std::cout << stack.top() << ' ';
        stack.pop();
    }
    std::cout << std::endl;

    std::queue<int> queue;
    for (int i{}; i < 10; ++i)
        queue.push(i);

    std::cout << "The lements coming from te front of the queue: ";
    while (not queue.empty()) {
        std::cout << queue.front() << ' ';
        queue.pop();
    }
    std::cout << std::endl;
}
