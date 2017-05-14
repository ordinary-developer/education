#include "AccessList.hpp"


AccessList::AccessList(const std::initializer_list<std::string>& initList) {
    for (auto& user : initList) {
        addUser(user);
    }
}

void AccessList::addUser(const std::string& user) {
    _allowed.insert(user);
}

void AccessList::removeUser(const std::string& user) {
    _allowed.erase(user);
}

bool AccessList::isAllowed(const std::string& user) const {
    return (_allowed.count(user) != 0);
}

std::list<std::string> AccessList::getAllUsers() const {
    std::list<std::string> users;
    users.insert(end(users), begin(_allowed), end(_allowed));
    return users;
}
