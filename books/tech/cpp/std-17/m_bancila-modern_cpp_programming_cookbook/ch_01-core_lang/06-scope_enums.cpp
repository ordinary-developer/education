// region [how to do it]
#include <iostream>
namespace example_01 {
    
enum class Status { Unknown, Created, Connected };
void run() {
    Status s = Status::Created;
}    
} // example_01
// endregion [how to do it]

// region [how it works]
namespace example_02 {
    
enum class Status { Unknown, Created, Connected };
enum class Codes { OK, Failure, Unknown };
    
void run() {
    Codes code = Codes::Unknown;
}    
} // example_02

namespace example_03 {

enum class Codes : unsigned int;    
    
void print_code(Codes const code) {}
    
enum class Codes : unsigned int {
    OK = 0,
    Failure = 1,
    Unknown = 0xFFFF0000U
}; 
    
void run() {
    print_code(Codes::OK);
} 
} // example_03

namespace example_04 {
    
enum class Codes { OK, Failure, Unknown };
    
void run() {
    Codes c1 = Codes::OK;
    int c3 = static_cast<int>(Codes::Failure);
}    
} // example_04
// endregion [how it works]

#include <iostream>
int main() {
    example_01::run();
    example_02::run();
    example_03::run();
    example_04::run();
    
    std::cout << "DONE" << std::endl;
    return 0;    
}