#include <string>
#include <stdexcept>
#include <cassert>
namespace workspace {

class CountryCode {
public:
    explicit CountryCode(const std::string& code) : code_(code) {
        if (KNOWN_CODES[0] != code_ && KNOWN_CODES[1] != code_)        
            throw std::invalid_argument(std::string("unknown country code ").append(code));
    }

private:
    static const std::string KNOWN_CODES[2];
    const std::string code_;
};
const std::string CountryCode::KNOWN_CODES[2] = { "NL", "GB" };

void run() {
    CountryCode("NL");
    CountryCode("GB");
    
    {
        bool wasException = false;
    
        const std::string invalidCode = "ABC";
    
        try {
            CountryCode _(invalidCode);    
        }
        catch (const std::invalid_argument& e) {        
            assert((std::string("unknown country code ").append(invalidCode) 
                == std::string(e.what())));
            assert((wasException = true));
        }       
        catch (...) { assert(false); }
        
        assert(wasException);
    }
}

} // workspace


int main() {
    workspace::run();

    return 0;
}
