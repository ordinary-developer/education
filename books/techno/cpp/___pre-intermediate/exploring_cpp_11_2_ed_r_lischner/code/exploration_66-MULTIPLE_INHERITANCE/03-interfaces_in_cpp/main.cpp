class Hashable {
    public:
        virtual ~Hashable() = default;

        virtual unsigned long hash() const = 0;
        virtual bool equalTo(Hashable const&) const = 0;
};

#include <string>
#include <unordered_set>
#include <utility>
class HashableString : public Hashable {
    public:
        HashableString() : string_{} { }
        HashableString(std::string const& str) : string_{str} { }

        virtual ~HashableString() final override = default;
        virtual unsigned long hash() const override {
            return std::hash<std::string>()(string_);
        }
        virtual bool equalTo(Hashable const& hashable) const override {
            return dynamic_cast<HashableString const&>(hashable) == *this;  
        }

        friend 
         bool operator==(HashableString const&, HashableString const& rhs); 

    private:
        std::string string_;
};

bool operator==(HashableString const& lhs, HashableString const& rhs) {
    return lhs.string_ == rhs.string_;
}


#include <iostream>
int main() {
    std::string str{};
    while (std::cin >> str) 
        std::cout << HashableString(str).hash() << std::endl;

    return 0;
}

