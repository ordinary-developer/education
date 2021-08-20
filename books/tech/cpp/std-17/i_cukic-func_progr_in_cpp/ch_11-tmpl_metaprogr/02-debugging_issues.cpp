#include <type_traits>
#include <list>
#include <string>
#include <vector>
namespace workspace {
    
template <typename T>
using contained_type_t = 
    std::remove_cv_t<
        std::remove_reference_t<decltype(*begin(std::declval<T>()))>>;

template <typename T>
class _stubForTypeTest;
    
void run() {
    // uncomment to see the real argument's type
    //_stubForTypeTest<contained_type_t<std::vector<std::string>>>{};   
    
    static_assert(
        std::is_same<int, contained_type_t<std::vector<int>>>{},
        "std::vector<int> should contain integers");
    
    static_assert(
        std::is_same<std::string, contained_type_t<std::list<std::string>>>{},
        "std::list<std::string> should contain strings");
}     

} // workspace 


int main() {
    workspace::run();
}
