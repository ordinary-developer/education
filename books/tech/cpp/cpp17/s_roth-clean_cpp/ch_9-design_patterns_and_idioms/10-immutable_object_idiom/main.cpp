#include <iostream>
#include <string>
#include <string_view>

// dumb class
class Identifier { };

// dumb class
class Money { };

class Employee final {
    public:
        Employee(std::string_view forename,
                 std::string_view surname,
                 Identifier const& staffNumber,
                 Money const& salary) noexcept 
            : forename_{ forename }, surname_{ surname }, 
              staffNumber_{ staffNumber }, salary_{ salary }
        {}

        Identifier getStaffNumber() const noexcept {
            return staffNumber_;
        }

        Money getSalary() const noexcept {
            return salary_;
        }

        Employee changeSalary(Money const& newSalary) const noexcept {
            return Employee(forename_,
                            surname_,
                            staffNumber_,
                            newSalary);
        }

    private:
        const std::string forename_;
        const std::string surname_;
        const Identifier staffNumber_;
        const Money salary_;
};

int main() {
    Employee employee("forename", 
                      "surname",
                      Identifier(),
                      Money());
    Employee newEmployee = employee.changeSalary(Money());

    std::cout << "[OK] - done" << std::endl;

    return 0;
}
