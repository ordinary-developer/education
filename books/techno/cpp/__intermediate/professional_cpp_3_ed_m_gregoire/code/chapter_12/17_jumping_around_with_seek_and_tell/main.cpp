#include <iostream>
#include <fstream>


auto main() -> int {
    std::ofstream fout("test.out");
    if (!fout) {
        std::cerr << "Error opening test.out for writing" << std::endl;
        return 1;
    }

    // 1. Output the string "12345"
    fout << "12345";

    // 2. Verify that the marker is at position 5
    std::ios_base::streampos curPos = fout.tellp();
    if (5 == curPos) {
        std::cout << "Test passed: Currently at position 5" << std::endl;
    }
    else {
        std::cout << "Test failed: Not at position 5" << std::endl;
    }

    // 3. Move to position 2 in the stream
    fout.seekp(2, std::ios_base::beg);

    // 4. Ouput a 0 in position 2 and close the stream
    fout << 0;
    fout.close();

    // 5. Open an input stream on test.out
    std::ifstream fin("test.out");
    if (!fin) {
        std::cerr << "Error opening test.out for reading" << std::endl;
        return 1;
    }

    // 6. Read the first token as an integer
    int testVal;
    fin >> testVal;

    // 7. Confirm that the value is 12045
    const int expected = 12045;
    if (expected == testVal) {
        std::cout << "Test passed: Value is " << expected << std::endl;
    }
    else {
        std::cout << "Test failed: Value is not " << expected
                  << "(it was " << testVal << ")" << std::endl;
    }

    return 0;
}
