
class generate_id {
    public:
        generate_id() : counter_{ 0 } { }
        long operator()() {
            if (max_counter_ == counter_)
                counter_ = 0;
            else
                ++counter_;

            return 
              static_cast<long>(prefix_) * (max_counter_  + 1)
                + counter_;
        }

    private:
        short counter_;
        static short prefix_;
        static short const max_counter_{ 32767 };
};

short generate_id::prefix_{ 1 };


#include <iostream>
bool get_movie(std::string& title, int& runtime) {
    std::cout << "Movie title: ";
    if (not std::getline(std::cin, title))
        return false;

    std::cout << "Runtime (minutes): ";
    if (not (std::cin >> runtime))
        return false;

    return true;
}



#include <string>
inline std::string int_to_id(int id) { return std::to_string(id); }

#include "library.hpp"
inline void accession(movie const& movie) { return; }

int main() {
    generate_id gen{};
    std::string title{};
    int runtime{};
    while (get_movie(title, runtime)) {
        movie m{ int_to_id(gen()), title, runtime };
        accession(m);
    }

    return 0;
}

