#include <exception>
#include <iostream>
#include <string>


class visual {
    public:
        visual(std::string const& what)
            : id_{ serial_ }, what_{ what } 
        {
            ++serial_;
            print("");
        }

        visual(visual const& ex) 
            : id_{ ex.id_ }, what_{ ex.what_ } { print("copy"); }

        ~visual() { print("~"); }

        void print(std::string const& label) const {
            std::cout << label << "visual(" << what_ << ": " << id_
                      << ")\n";
        }

    private:
        static int serial_;
        int const id_;
        std::string const what_;
};

int visual::serial_{ 0 };

void count_down(int n) {
    std::cout << "start cound_down(" << n << ")\n";
    visual v{ "count_down local" };
    try {
        if (3 == n)
            throw visual("exception");
        else if (n > 0)
            count_down(n - 1);
    }
    catch (visual ex) {
        ex.print("catch ");
        throw;
    }
}

int main() {
    try {
        count_down(2);
        count_down(4);
    }
    catch (visual const ex) {
        ex.print("catch ");
    }
    std::cout << "All donw!\n";
    return 0;
}
