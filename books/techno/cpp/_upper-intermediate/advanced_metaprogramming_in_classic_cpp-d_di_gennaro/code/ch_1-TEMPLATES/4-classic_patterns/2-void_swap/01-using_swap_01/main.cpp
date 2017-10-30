
#include <vector>
#include <string>
#include <utility>
namespace example_1 {
    class TheClass {
        public:
            void swap(TheClass& that) {
                theString_.swap(that.theString_);
                theVector_.swap(that.theVector_);
                std::swap(theDouble_, that.theDouble_);
            }

        private:
            std::vector<double> theVector_;
            std::string theString_;
            double theDouble_;
    };

    void run() {
        TheClass a1, a2;
        a1.swap(a2);
    }
}


#include <utility>
namespace example_2 {
    using std::swap;

    template <typename T>
    inline void swap_with_ADL(T& a, T& b) {
        swap(a, b);
    }

    template <typename T>
    class TheClass {
        public:
            void swap(TheClass<T>& that) {
                swap_with_ADL(_theObj, that._theObj);
            }

        private:
            T _theObj;
    };


    void run() {
        TheClass<int> a1, a2;
        a1.swap(a2);
    }

};


#include <utility>
#include <vector>
#include <algorithm>
namespace example_3 {
    template <typename T>
    class sorted_vector {
        public:
            void swap(sorted_vector<T>& that) {
                data_.swap(that.data_);
            }

            void swap(std::vector<T>& that) {
                data_.swap(that);
                std::sort(data_.begin(), data_.end());
            }

        private:
            std::vector<T> data_;
    };

    
    void run() {
        sorted_vector<int> a1, a2;
        a1.swap(a2);

        std::vector<int> b1{ 42 };
        a1.swap(b1);
    }
};


#include <algorithm>
#include <utility>
#include <vector>
#include <cassert>
namespace example_4 {
    struct unchecked_type_t { };
    inline unchecked_type_t unchecked() { 
        return unchecked_type_t{ }; 
    }

    template <typename T>
    class sorted_vector {
        public:
            void swap(sorted_vector<T>& that) {
                data_.swap(that.data_);
            }

            void swap(std::vector<T>& that, unchecked_type_t (*)()) {
                assert(is_sorted(that.begin(), that.end()));
                data_.swap(that);
            }

        private:
            std::vector<T> data_;
    };


    void run() {
        sorted_vector<double> x;
        std::vector<double> t{ 3, 2, 1 };

        x.swap(t, unchecked); // very fast
    }
};



int main() {
    example_1::run();
    example_2::run();
    example_3::run();
    example_4::run();

    return 0;
}
