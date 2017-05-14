#include <thread>
#include <iostream>
#include <algorithm>
#include <vector>


template <typename Iterator, typename T>
struct accumulate_block {
    void operator() (Iterator first, Iterator last, T& result) {
        result = std::accumulate(first, last, result);
    }
};

template <typename Iterator, typename T>
T parallel_accumulate(Iterator first, Iterator last, T init) {
    unsigned long const length = std::distance(first, last);
    if (!length) {
        return init;
    }

    unsigned long const min_per_thread = 25;
    unsigned long const max_threads = 
        (length + min_per_thread - 1) / min_per_thread;
    unsigned long const hardware_threads = 
        std::thread::hardware_concurrency();
    unsigned long const num_threads = 
        std::min((0 != hardware_threads ? hardware_threads : 2),    
                 max_threads);
    unsigned long const block_size = length / num_threads;

    std::vector<T> results(num_threads);
    std::vector<std::thread> threads(num_threads - 1);

    Iterator block_start = first;
    for (unsigned long i = 0; i < (num_threads - 1); ++i) {
        Iterator block_end = block_start;
        std::advance(block_end, block_size);
        threads[i] = std::thread(
            accumulate_block<Iterator, T>(),
            block_start, block_end, std::ref(results[i]));
        block_start = block_end;
    }

    accumulate_block<Iterator, T>()(
        block_start, last, results[num_threads - 1]);

    std::for_each(threads.begin(), threads.end(),
        std::mem_fn(&std::thread::join));

    return std::accumulate(results.begin(), results.end(), init);
}


int main() {
    std::vector<int> vector;
    for (int i = 0; i < 100000000; ++i) {
        vector.push_back(i);
    }
    std::cout << "[OK] - initializing data" << std::endl;

    auto result = 
        parallel_accumulate(std::begin(vector), std::end(vector), 0);
    std::cout << "[OK] - parallel version: " << result << std::endl;


    result = 0;
    for (int i = 0; i < vector.size(); ++i) {
        result += vector[i];
    }
    std::cout << "[OK] - sequential version: " << result << std::endl;

    return 0;
}
