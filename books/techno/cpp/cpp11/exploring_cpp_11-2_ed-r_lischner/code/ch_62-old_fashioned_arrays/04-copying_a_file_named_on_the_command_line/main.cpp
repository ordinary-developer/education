#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>


int main(int argc, char* argv[]) {
    if (3 != argc) {
        std::cerr << "usage: " << argv[0] << " INPUT OUTPUT\n";
        return EXIT_FAILURE;
    }

    std::ifstream input{argv[1]};
    if (not input) {
        std::perror(argv[1]);
        return EXIT_FAILURE;
    }

    std::ofstream output{ argv[2] };
    if (not output) {
        std::perror(argv[2]);
        return EXIT_FAILURE;
    }

    input.exceptions(input.badbit);
    output.exceptions(output.failbit);

    try {
        output << input.rdbuf();
        output.close();
        input.close();
    }
    catch (std::ios_base::failure const& ex) {
        std::cerr << "Can't copy " << argv[1] << " to " << argv[2] << ": "
                  << ex.what() << '\n';
        return EXIT_FAILURE;
    }
    return 0;
}
