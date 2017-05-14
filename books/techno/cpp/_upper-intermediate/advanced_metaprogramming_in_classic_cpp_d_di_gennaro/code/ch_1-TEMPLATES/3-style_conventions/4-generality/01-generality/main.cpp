#include <utility>

struct id_and_value {
    int id;
    double value;
};

id_and_value FindIDAndValue_() { return id_and_value(); }

std::pair<int, double> FindIDAndValue() { 
    return std::pair<int, double>(1, 1.0);
}

// macros
// #define id          first  // bad idea
// #define value       second // bad idea

// slightly a better approach
#define MXT_M_ID(P)           P.first
#define MXT_M_VALUE(P)        P.second

// global functions (accessors)
inline int& id(std::pair<int, double>& P) { return P.first; }
inline int id(const std::pair<int, double>& P) { return P.first; }

// global pointer-to-members
typedef std::pair<int, double> id_value;
int id_value::*ID = &id_value::first;
double id_value::*VALUE = &id_value::second;


#include <iostream>
int main() {
    auto data = FindIDAndValue();

    std::cout << "example 1 => " << std::endl;
    std::cout << "id = " << MXT_M_ID(data) << std::endl;
    std::cout << "value = " << MXT_M_VALUE(data) << std::endl;

    std::cout << "example 2 => " << std::endl;
    std::cout << "id = " << id(data) << std::endl;

    std::cout << "example 3 => " << std::endl;
    std::cout << "id = " << data.*ID << std::endl;
    std::cout << "value = " << data.*VALUE << std::endl;

    return 0;
}
