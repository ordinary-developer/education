#include "person.h"
namespace workspace {

auto print_person_cd(person_t const& person) {
    return [&](std::ostream& out) {
        return [&](person_t::output_format_t format) {
            //print_person(person, out, format);
            person.print(out, format);
        };
    };
}
    
void run() {
    person_t const martha{ "Martha", "Jones", person_t::gender_t::female, 37 };
    print_person_cd(martha)(std::cout)(person_t::full_name);
}

} // workspace


int main() {
    workspace::run();    
}
