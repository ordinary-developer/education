#include <chrono>
#include <iostream>


const int NUM_ROWS{ 10000 };
const int NUM_COLUMNS{ 1000 };
int elements[NUM_ROWS][NUM_COLUMNS];
int* pElements[NUM_ROWS][NUM_COLUMNS];

int main() {
    for (int i{ 0 }; i < NUM_ROWS; ++i) {
        for (int j{ 0 }; j < NUM_COLUMNS; ++j) {
            elements[i][j] = i * j;
            pElements[i][j] = new int{ elements[i][j] };
        }
    }

    auto start = std::chrono::high_resolution_clock::now();
    for (int i{ 0 }; i < NUM_ROWS; ++i) 
        for (int j{ 0 }; j < NUM_COLUMNS; ++j)
            const int result{ elements[j][i] };
    auto end = std::chrono::high_resolution_clock::now();
    auto difference = end - start;
    std::cout 
        << "Time taken for j then i: "
        << std::chrono::duration_cast<std::chrono::microseconds>(difference).count()
        << " microseconds!" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    for (int i{ 0 }; i < NUM_ROWS; ++i) 
        for (int j{ 0 }; j < NUM_COLUMNS; ++j)
            const int result{ elements[i][j] };
    end = std::chrono::high_resolution_clock::now();
    difference = end - start;
    std::cout 
        << "Time taken for i then j: "
        << std::chrono::duration_cast<std::chrono::microseconds>(difference).count()
        << " microseconds!" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    for (int i{ 0 }; i < NUM_ROWS; ++i) 
        for (int j{ 0 }; j < NUM_COLUMNS; ++j)
            const int result{ *(pElements[i][j]) };
    end = std::chrono::high_resolution_clock::now();
    difference = end - start;
    std::cout 
        << "Time taken for pointers with i then j: "
        << std::chrono::duration_cast<std::chrono::microseconds>(difference).count()
        << " microseconds!" << std::endl;

    return 0;
}
