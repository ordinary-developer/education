namespace example1 {
void run() {
    char board[3][3];
    board[0][0] = 'X';
    board[2][1] = 'O';
}
}

#include <cstddef>
namespace example2 {
char** allocateCharBoard(size_t xDimension, size_t yDimension) {
    char** myArray = new char*[xDimension];
    for (size_t i{0}; i < xDimension; ++i)
        myArray[i] = new char[yDimension];

    return myArray;
}

void releaseCharBoard(char** myArray, size_t xDimension) {
    for (size_t i{0}; i < xDimension; ++i) {
        delete [] myArray[i];
        myArray[i] = nullptr;
    }
    delete [] myArray;
    myArray = nullptr;
}

void run() {
    char** charBoard = allocateCharBoard(3, 3);
    releaseCharBoard(charBoard, 3);
}
}

int main() {
    example1::run();
    example2::run();

    return 0;
}
