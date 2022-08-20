#ifndef BUDDY_LIST_HPP
#define BUDDY_LIST_HPP

#include <map>
#include <string>
#include <list>


class BuddyList {
    public:
        void addBuddy(const std::string& name, const std::string& buddy);
        void removeBuddy(const std::string& name, const std::string& buddy);

        bool isBuddy(const std::string& name, const std::string& buddy) const;
        std::list<std::string> getBuddies(const std::string& name) const;
    private:
        std::multimap<std::string, std::string> _buddies;
};
#endif
