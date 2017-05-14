#include <algorithm>
#include <iostream>
#include <iterator>
#include <map>
#include <string>

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

    bool operator<(token const& a, token const & b) {
        return a.text() < b.text();
    }


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

    std::ostream& operator<<(std::ostream& out, 
                             std::pair<const token, long> const& count) 
    {
        out << count.first.text() << '\t' << count.second << '\n';
        return out;
    }
}


int main() {
    using namespace parser;

    std::map<token, long> tokens{};
    token tok{};
    while (std::cin >> tok) 
        ++tokens[tok];

    std::copy(tokens.begin(), 
              tokens.end(),
              std::ostream_iterator<std::pair<const token, long>>(std::cout));

    return 0;
}
