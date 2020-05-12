#include <queue>
#include <iostream>


auto main() -> int {
    std::priority_queue<int> queue1;
    queue1.push(3);
    queue1.push(4);
    queue1.push(2);
    queue1.push(1);
    while (!queue1.empty()) {
        std::cout << queue1.top() << " ";
        queue1.pop();
    }
    std::cout << std::endl;

    std::priority_queue<int, std::vector<int>, std::greater<>> queue2;
    queue2.push(3);
    queue2.push(4);
    queue2.push(2);
    queue2.push(1);

    while (!queue2.empty()) {
        std::cout << queue2.top() << " ";
        queue2.pop();
    }
    std::cout << std::endl;

    return 0;
}
