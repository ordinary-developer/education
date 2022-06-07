#include <fstream>
#include <vector>

#include <iostream>
#include <iomanip>
namespace example_01 { // -> the "how to do it..." section

void run() {
    {
        std::ofstream ofile("sample.bin", std::ios::binary);
        if (ofile.is_open()) {
            std::vector<unsigned char> output{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
            ofile.write(reinterpret_cast<char*>(output.data()), output.size());
            ofile.close();
        }
    }
    
    {    
        std::ifstream ifile("sample.bin", std::ios::binary);
        if (ifile.is_open()) {
            ifile.seekg(0, std::ios_base::end);
            auto length = ifile.tellg();
            ifile.seekg(0, std::ios_base::beg);
            
            std::vector<unsigned char> input;
            input.resize(static_cast<size_t>(length));
        
            ifile.read(reinterpret_cast<char*>(input.data()), length);
        
            std::cout << std::boolalpha;
            auto const success = not ifile.fail() and length == ifile.gcount();
            std::cout << "reading from file status = " << success << std::endl;
            
            ifile.close();
        }   
    }
}

} // example_01


#include <fstream>
#include <functional>

#include <iostream>
namespace example_02 { // -> the "how it works..." section
    
bool write_data(char const * const filename,
                char const * const data,
                std::size_t const size)
{
    auto success = false;
    std::ofstream ofile(filename, std::ios::binary);
    
    if (ofile.is_open()) {
        try {
            ofile.write(data, size);
            success = true;
        }
        catch (std::ios_base::failure const &) {}
        
        ofile.close();
    }
    
    return success;
}

std::size_t read_data(char const * const filename,
                      std::function<char*(std::size_t const)> allocator)
{
    std::size_t readbytes = 0;
    std::ifstream ifile(filename, std::ios::ate | std::ios::binary);
    
    if (ifile.is_open()) {
        auto length = static_cast<std::size_t>(ifile.tellg());
        ifile.seekg(0, std::ios_base::beg);
        
        auto buffer = allocator(length);
        
        try {
            ifile.read(buffer, length);
            readbytes = static_cast<std::size_t>(ifile.gcount());
        }
        catch (std::ios_base::failure const &) {}
        
        ifile.close();
    }
    
    return readbytes;
}
    
void run() {
    {
        std::vector<unsigned char> output{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        std::vector<unsigned char> input;
        
        if (write_data("sample.bin", reinterpret_cast<char*>(output.data()), output.size())) {
            if (read_data("sample.bin",
                          [&input](std::size_t const length) {
                              input.resize(length);
                              return reinterpret_cast<char*>(input.data());
                          }) > 0)
            {
                std::cout << (output == input ? "equal" : "not equal") << '\n';
            }
        }
    }
    
    {
        std::vector<unsigned char> output{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
        unsigned char * input = nullptr;
        std::size_t readb = 0;
        
        if (write_data("sample.bin", reinterpret_cast<char*>(output.data()), output.size())) {
            if ((readb = read_data(
                            "sample.bin",
                            [&input](std::size_t const length) {
                                input = new unsigned char[length];
                                return reinterpret_cast<char*>(input);
                            })) > 0)
            {
                auto cmp = memcmp(output.data(), input, output.size());
                std::cout << (0 == cmp ? "equal" : "not equal") << '\n';
            }
        }
        
        delete [] input;
    }
}

} // example_02


#include <iterator>
#include <fstream>
#include <vector>
namespace example_03 { // -> the "there's more..." section
    
void run() {
    {
        std::vector<unsigned char> input;
        std::ifstream ifile("sample.bin", std::ios::binary);
        if (ifile.is_open()) {
            input = std::vector<unsigned char>(
                std::istreambuf_iterator<char>(ifile),
                std::istreambuf_iterator<char>());
                
            ifile.close();
        }
    }
    
    {
        std::vector<unsigned char> input;
        std::ifstream ifile("sample.bin", std::ios::binary);
        if (ifile.is_open()) {
            ifile.seekg(0, std::ios_base::end);
            auto length = ifile.tellg();
            ifile.seekg(0, std::ios_base::beg);
            
            input.reserve(static_cast<std::size_t>(length));
            input.assign(
                std::istreambuf_iterator<char>(ifile),
                std::istreambuf_iterator<char>());
                
            ifile.close();
        }
    }
    
    {
        std::vector<unsigned char> input;
        std::ifstream ifile("sample.bin", std::ios::binary);
        if (ifile.is_open()) {
            ifile.seekg(0, std::ios_base::end);
            auto length = ifile.tellg();
            ifile.seekg(0, std::ios_base::beg);
            
            input.reserve(static_cast<std::size_t>(length));
            std::copy(std::istreambuf_iterator<char>(ifile),
                std::istreambuf_iterator<char>(),
                std::back_inserter(input));
            
            ifile.close();
        }
    }
}    

}


#include <iostream>
int main() {
    std::cout << "example_01 -->" << std::endl;
    example_01::run();
    std::cout << "-> ok" << std::endl << std::endl;
    
    std::cout << "example_02 -->" << std::endl;
    example_02::run();
    std::cout << "-> ok" << std::endl << std::endl;
    
    std::cout << "example_03 -->" << std::endl;
    example_03::run();
    std::cout << "-> ok" << std::endl << std::endl;
    
    return 0;
}
