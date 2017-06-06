#include "AccessList.hpp"

#include <iostream>


auto main() -> int {
    AccessList fileX = { "pvw", "mgregoire", "baduser" };
    fileX.removeUser("baduser");

    if (fileX.isAllowed("mgregoire")) {
        std::cout << "mgregoire has permissions" << std::endl;
    }
    if (fileX.isAllowed("baduser")) {
        std::cout << "baseuser has permissions" << std::endl;
    }

    auto users = fileX.getAllUsers();
    for (const auto& user : users) {
        std::cout << user << " ";
    }
    std::cout << std::endl;

    return 0;
}
