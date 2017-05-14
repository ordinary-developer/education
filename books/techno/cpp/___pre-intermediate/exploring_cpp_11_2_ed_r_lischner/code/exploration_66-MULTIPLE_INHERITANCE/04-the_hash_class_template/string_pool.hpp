#pragma once

#include <unordered_set>
#include <string>


class string_pool {
    public:
        string_pool() : pool_{} {}

        ~string_pool() {
            while (not pool_.empty()) {
                std::string* ptr{ *pool_.begin() };
                pool_.erase(pool_.begin());
                delete ptr;
                ptr = nullptr;
            }
        }

        std::string* add(std::string&& str) {
            std::string* ptr{ new std::string{std::move(str)} };
            pool_.insert(ptr);
            return ptr;
        }

    private:
        std::unordered_set<std::string*> pool_;
};
