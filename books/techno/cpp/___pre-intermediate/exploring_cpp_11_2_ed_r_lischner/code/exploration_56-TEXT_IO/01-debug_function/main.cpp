#include <fstream>
#include <ostream>
#include <stdexcept>
#include <string>


void debug(std::string const& str) {
    std::ofstream stream{ "debug.txt", std::ios_base::out | std::ios_base::app };
    if (not stream) 
        throw std::runtime_error("cannot open debug.txt");
    stream.exceptions(std::ios_base::failbit);
    stream << str << '\n';
    stream.close();
}


int main() {
    debug("line 1");
    debug("line 2");

    return 0;
}
