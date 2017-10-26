#ifndef ACCESS_LIST_HPP
#define ACCESS_LIST_HPP

#include <set>
#include <string>
#include <initializer_list>
#include <list>


class AccessList {
    public:
        AccessList() = default;
        AccessList(const std::initializer_list<std::string>& initList);

        void addUser(const std::string& user);
        void removeUser(const std::string& user);

        bool isAllowed(const std::string& user) const;
        std::list<std::string> getAllUsers() const;
    private:
        std::set<std::string> _allowed;
};

#endif
