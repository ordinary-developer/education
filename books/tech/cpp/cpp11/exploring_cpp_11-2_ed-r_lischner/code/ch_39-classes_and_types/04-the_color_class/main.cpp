#include <iomanip>
#include <iostream>
#include <sstream>


class color {
    public:
        color() : color{ 0, 0, 0 } { }
        color(color const&) = default;
        color(int r, int g, int b) 
            : red_{ r }, green_{ g }, blue_{ b } { }

        int red() const { return red_; }
        int green() const { return green_; }
        int blue() const { return blue_; }

        long int combined() const { 
            return ((red() * 256L + green()) * 256) + blue();
        }

    private:
        int red_, green_, blue_;
};

inline bool operator==(color const& a, color const& b) {
    return a.combined() == b.combined();
}

inline bool operator!=(color const& a, color const& b) {
    return not (a == b);
}

inline bool order_color(color const& a, color const& b) {
    return a.combined() < b.combined();
}

std::ostream& operator<<(std::ostream& out, color const& c) {
    std::ostringstream tmp{};
    tmp << '#' << std::hex << std::setw(6) << std::setfill('0')
        << c.combined();
    out << tmp.str();
    return out;
}


class ioflags {
    public:
        ioflags(std::basic_ios<char>& stream) 
            : stream_{ stream }, flags_{ stream.flags() } { }

        ioflags(ioflags const&) = delete;

        ~ioflags() { stream_.flags(flags_); }

    private:
        std::basic_ios<char>& stream_;
        std::ios_base::fmtflags flags_;
};

std::istream& operator>>(std::istream& in, color& c) {
    ioflags flags{ in };

    char hash{};
    if (not (in >> hash))
        return in;
    if ('#' != hash) {
        in.unget();
        in.setstate(in.failbit);
        return in;
    }

    int combined{};
    in >> std::hex >> std::noskipws;
    if (not (in >> combined))
        return in;
    int red, green, blue;
    blue = combined % 256;
    combined = combined / 256;
    green = combined % 256;
    combined = combined / 256;
    red = combined % 256;

    c = color{ red, green, blue };

    return in;
}

int main() {
    std::cout << "Input the color: " << std::endl;
    color c{};
    std::cin >> c;
    std::cout << c << std::endl;

    return 0;
}
