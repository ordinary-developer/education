#include <iostream>
#include <set>

void printSet(const std::set<int> & mySet);

int main() {
    std::set<int> mySet;

    mySet.insert(1);
    mySet.insert(4);
    mySet.insert(3);
    mySet.insert(3);
    mySet.insert(1);
    mySet.insert(2);

    printSet(mySet);

    std::cout << "The element 1 occurs " << mySet.count(1) << " time(s)" << std::endl;

    mySet.erase(1);
    printSet(mySet);

    mySet.clear();
    printSet(mySet);
}

void printSet(const std::set<int> & mySet) {
    std::cout << "Ther are " << mySet.size() << " elements in mySet: ";
    for (int element : mySet)
        std::cout << element << ' ';
    std::cout << std::endl;
}
