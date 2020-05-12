#include "BuddyList.hpp"

void BuddyList::addBuddy(const std::string& name, const std::string& buddy) {
    if (!isBuddy(name, buddy)) {
        _buddies.insert({ name, buddy });
    }
}

void BuddyList::removeBuddy(const std::string& name, const std::string& buddy) {
    auto iterator = _buddies.lower_bound(name);
    auto end = _buddies.upper_bound(name);

    for (; iterator != end; ++iterator) {
        if (buddy == iterator->second) {
            _buddies.erase(iterator);
            break;
        }
    }
}


bool BuddyList::isBuddy(const std::string& name, const std::string& buddy) const {
    auto range = _buddies.equal_range(name);
    auto iterator = range.first;
    auto end = range.second;

    for (; iterator != end; ++iterator) {
        if (buddy == iterator->second) {
            return true;
        }
    }

    return false;
}


std::list<std::string> BuddyList::getBuddies(const std::string& name) const {
    auto range = _buddies.equal_range(name);
    auto iterator = range.first;
    auto end = range.second;

    std::list<std::string> buddies;
    for (; iterator != end; ++iterator) {
        buddies.push_back(iterator->second);
    }

    return buddies;
}
