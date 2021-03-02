#include <string>
#include <cassert>
namespace test_01 { // -> immutable vars

void run() {
    std::string const name{ "John Smith" };
    
    std::string const name_copy = name;
    assert(name == name_copy);

    std::string const& name_constref = name;
    assert(name == name_constref);

    const std::string* name_constptr1 = &name;
    assert(name == *name_constptr1);

    const std::string* const name_constptr2 = &name;  
    assert(name == *name_constptr2);    
}

} // test_01


#include <string>
#include <cassert>
namespace test_02 { // -> immutable objects
class person_t {
public:
    person_t(std::string const& name, int const id) : name_{name}, id_{id} {}

    person_t with_name(std::string const& name) const {
        return person_t{name, id_};        
    }

    std::string name() const { return name_; }

private:
    std::string const name_;
    int const id_;
};

void run() {
    person_t const& person = person_t{"John Smith", 1}.with_name("John Brown");
    assert("John Brown" == person.name());
}

} // test_02


#include <iostream>
int main() {
    std::cout << "test_01 => [ok]" << std::endl; test_01::run(); std::cout << std::endl;
    std::cout << "test_02 => [ok]" << std::endl; test_02::run(); std::cout << std::endl;    

    return 0;
}
