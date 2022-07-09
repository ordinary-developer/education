#include <deque>
#include <iostream>


int main() {
    std::deque<int> myDeque;
    
    myDeque.push_back(2);
    myDeque.push_back(4);
    myDeque.push_front(1);
    myDeque[2] = 3;

    std::cout << "There are " << myDeque.size() << " elements in myDeque: ";
    for (int element : myDeque)
        std::cout << element << ' ';
    std::cout << std::endl;
}
