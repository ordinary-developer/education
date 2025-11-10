#include <iostream>
#include <span>
namespace example_01 { // -> the "how to do it..." section

void func(std::span<int> buffer) {
    for (auto const e : buffer)
        std::cout << e << ' ';
    std::cout << '\n';
}

void run() {
    {
        int arr[] = { 1, 1, 2, 3, 5, 8, 13 };
        std::span<int, 7> s{arr};
        func(s);
    }
    
    {
        int arr[] = { 1, 1, 2, 3, 5, 8, 13 };
        std::span<int> s{arr};
        func(s); 
    }
    
    {
        int arr[] = { 1, 1, 2, 3, 5, 8, 13 };
        std::span<int, 7> s{arr};
        std::cout << s.front() << " == " << s[0] << '\n';
        std::cout << s.back() << " == " << s[s.size() - 1] << '\n';
    }
    
    {
        int arr[] = { 1, 1, 2, 3, 5, 8, 13 };
        std::span<int, 7> s{arr};
        
        std::span<int> first_3 = s.first(3);
        func(first_3);
        
        std::span<int> last_3 = s.last(3);
        func(last_3);
        
        std::span<int> mid_3 = s.subspan(2, 3);
        func(mid_3);
    }

}

} // example_01


#include <iostream>
int main() {
    std::cout << "example_01 -->" << std::endl;
    example_01::run();
    std::cout << "-> ok" << std::endl << std::endl;
    
    return 0;
}
