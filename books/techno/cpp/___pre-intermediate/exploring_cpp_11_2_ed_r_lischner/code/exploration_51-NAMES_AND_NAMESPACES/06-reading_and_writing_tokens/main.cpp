#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

namespace parser {
    class token {
        public:
            token() : text_{} { }
            token(std::string& s) : text_{ s } { }

            token& operator=(std::string const& s) { text_ = s; return *this; }

            std::string text() const { return text_; }

        private:
            std::string text_;
    };

    std::istream& operator>>(std::istream& in, parser::token& tok) {
        std::string str{};
        if (in >> str)
            tok = str;
        return in;
    }

    std::ostream& operator<<(std::ostream& out, parser::token const& tok) {
        out << tok.text();
        return out;
    }
}


int main() {
    using namespace parser;

    std::vector<token> tokens{};
    std::copy(std::istream_iterator<token>(std::cin),
              std::istream_iterator<token>(),
              std::back_inserter(tokens));
    std::copy(tokens.begin(), 
              tokens.end(), 
              std::ostream_iterator<token>(std::cout, "\n"));

    return 0;
}
