#include <atomic>
#include <iostream>

int main()
{
    std::atomic<int> x{0};
    int res = 0;

    x.store(17);
    res = x.load();
    std::cout << res << std::endl;
    
    x.store(42, std::memory_order_seq_cst);
    res = x.load(std::memory_order_seq_cst);
    std::cout << res << std::endl;
}