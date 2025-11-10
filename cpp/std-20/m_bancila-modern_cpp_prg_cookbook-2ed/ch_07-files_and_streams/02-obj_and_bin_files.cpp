#include <fstream>
#include <string>
#include <vector>

#include <iostream>
#include <iomanip>
namespace example_01 { // -> the "how to do it..." section

class foo {
    int i;
    char c;
    std::string s;
    
public:
    foo(int const i = 0, char const c = 0, std::string const & s = {})
        :i(i), c(c), s(s)
    {}
    
    foo(foo const &) = default;
    foo & operator = (foo const &) = default;
    
    bool operator == (foo const & rhv) const { return i == rhv.i and c == rhv.c and s == rhv.s; }
    
    bool operator != (foo const & rhv) const { return not (*this == rhv); }
    
    bool write(std::ofstream & ofile) const {
        ofile.write(reinterpret_cast<const char*>(&i), sizeof(i));
        ofile.write(&c, sizeof(c));
        auto size = static_cast<int>(s.size());
        ofile.write(reinterpret_cast<char*>(&size), sizeof(size));
        ofile.write(s.data(), s.size());
        
        return not ofile.fail();
    }
    
    bool read(std::ifstream & ifile) {
        ifile.read(reinterpret_cast<char*>(&i), sizeof(i));
        ifile.read(&c, sizeof(c));
        auto size{0};
        ifile.read(reinterpret_cast<char*>(&size), sizeof(size));
        s.resize(size);
        ifile.read(reinterpret_cast<char*>(&s.front()), size);
        
        return not ifile.fail();
    }
    
    friend std::ofstream & operator << (std::ofstream & ofile, foo const & f);
    friend std::ifstream & operator >> (std::ifstream & ifile, foo & f);
};

std::ofstream & operator << (std::ofstream & ofile, foo const & f) {
    ofile.write(reinterpret_cast<const char*>(&f.i), sizeof(f.i));
    ofile.write(&f.c, sizeof(f.c));
    auto size = static_cast<int>(f.s.size());
    ofile.write(reinterpret_cast<char*>(&size), sizeof(size));
    ofile.write(f.s.data(), f.s.size());
    
    return ofile;
}

std::ifstream & operator >> (std::ifstream & ifile, foo & f) {
    ifile.read(reinterpret_cast<char*>(&f.i), sizeof(f.i));
    ifile.read(&f.c, sizeof(f.c));
    auto size{0};
    ifile.read(reinterpret_cast<char*>(&size), sizeof(size));
    f.s.resize(size);
    ifile.read(reinterpret_cast<char*>(&f.s.front()), size);
    
    return ifile;
}

struct foopod {
    bool a;
    char b;
    int c[2];
};

bool operator == (foopod const & f1, foopod const & f2) {
    return f1.a == f2.a and f1.b == f2.b and f1.c[0] == f2.c[0] and f1.c[1] == f2.c[1];
}


void run() {
    {
        // write
        std::vector<foopod> const output {
            { true, '1', { 1, 2 } },
            { true, '2', { 3, 4 } },
            { false, '3', { 4, 5 } }
        };
        
        std::ofstream ofile("sample.bin", std::ios::binary);
        if (ofile.is_open()) {
            for (auto const & value : output) {
                ofile.write(reinterpret_cast<const char*>(&value), sizeof(value));
            }
            ofile.close();
        }
    
        // read
        std::vector<foopod> input;
        std::ifstream ifile("sample.bin", std::ios::binary);
        if (ifile.is_open()) {
            while (true) {
                foopod value;
                ifile.read(reinterpret_cast<char*>(&value), sizeof(value));
                
                if (ifile.fail() or ifile.eof())
                    break;
                
                input.push_back(value);
            }
            
            ifile.close();
        }
        
        std::cout << (output == input ? "equal" : "not equal") << '\n';
    }
    
    {
        using namespace std::string_literals;
        
        auto f = foo{ 1, '1', "1"s };
        std::ofstream ofile("sample.bin", std::ios::binary);
        if (ofile.is_open()) {
            f.write(ofile);
            ofile.close();
        }
        
        auto f2 = foo{};
        std::ifstream ifile("sample.bin", std::ios::binary);
        if (ifile.is_open()) {
            f2.read(ifile);
            ifile.close();
        }
        
        std::cout << (f == f2 ? "equal" : "not equal") << '\n';
    }
    
    {
        using namespace std::string_literals;
        
        auto f = foo{ 1, '1', "1"s };
        std::ofstream ofile("sample.bin", std::ios::binary);
        if (ofile.is_open()) {
            ofile << f;
            ofile.close();
        }
        
        auto f2 = foo{};
        std::ifstream ifile("sample.bin", std::ios::binary);
        if (ifile.is_open()) {
            ifile >> f2;
            ifile.close();
        }
        
        std::cout << (f == f2 ? "equal" : "not equal") << '\n';
    }
}

} // example_01



#include <iostream>
int main() {
    std::cout << "example_01 -->" << std::endl;
    example_01::run();
    std::cout << "-> ok" << std::endl << std::endl;
    
    return 0;
}
