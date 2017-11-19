int main() {
    int myArray[5]{};

    int* myArrayPtr = new int[5]{};
    delete [] myArrayPtr;

    return 0;
}
