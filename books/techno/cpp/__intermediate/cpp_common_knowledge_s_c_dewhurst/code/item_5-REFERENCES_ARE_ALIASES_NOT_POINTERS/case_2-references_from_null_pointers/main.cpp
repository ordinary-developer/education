#include <iostream>

class Employee { };

Employee* getEmployee() {
    return 0;
}

int main()
{
    Employee& anEmployee = *getEmployee();
    if (&anEmployee == 0) { // undefined behavior
        std::cout << "Not proper using" << std::endl;
    }

    // a better approach
    Employee* employee = getEmployee();
    if (!employee) {
        std::cout << "A better using " << std::endl;
    }

    return 0;
}