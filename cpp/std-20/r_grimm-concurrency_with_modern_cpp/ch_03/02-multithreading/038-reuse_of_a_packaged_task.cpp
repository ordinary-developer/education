#include <functional>
#include <future>
#include <iostream>
#include <utility>
#include <vector>


void calcProducts(std::packaged_task<int(int, int)> & task,
                  const std::vector<std::pair<int, int>> & pairs)
{
    for (auto & pair : pairs) {
        auto f = task.get_future();
        task(pair.first, pair.second);
        std::cout << "[ .... ] " << pair.first << " * " << pair.second << " = " << f.get() << std::endl;
        task.reset();
    }
}


int main() {
    std::vector<std::pair<int, int>> allPairs;
    allPairs.push_back(std::make_pair(1, 2));
    allPairs.push_back(std::make_pair(2, 3));
    allPairs.push_back(std::make_pair(3, 4));
    allPairs.push_back(std::make_pair(4, 5));

    std::packaged_task<int(int, int)> task{[](int first, int second) {
        return first * second;
    }};

    calcProducts(task, allPairs);

    std::cout << "[ .... ]" << std::endl;

    std::thread t(calcProducts, std::ref(task), std::ref(allPairs));
    t.join();
}
