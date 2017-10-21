#include <memory>
#include <algorithm>
#include <cassert>
#include <iostream>
#include <cstddef>
namespace example01 {

template <typename T>
class my_vector {
    public:
        explicit my_vector(int size) 
            : size_{size}, data_{ new T[size_] } { }

        my_vector(my_vector const& that) 
            : size_{that.size_}, data_{ new T[size_] }
        {
            std::copy(&that.data_[0], &that.data_[that.size_]);
        }

        int size() const { return size_; }

        T const& operator[](int i) const {
            return data_[i];
        }

    private:
        void check_index(int i) {
            if (i < 0 or i >= size_)
                assert(false);
        }

        int size_;
        std::unique_ptr<T[]> data_;
};

void run() { 
    my_vector<int> const data(5);
    for (int i = 0; i < data.size(); ++i)
        std::cout << data[i] << std::endl;
}

} // namespace example01

namespace example02 {

struct row_major {};
struct col_major {};
struct heap {};
struct stack {};

template <typename T = double, 
          typename Orientation = col_major,
          typename Where = heap>
class my_vector {};

void run() {
    my_vector<float, row_major, heap> v1{};
    static_cast<void>(v1);

    my_vector<float, row_major> v2{};
    static_cast<void>(v2);

    my_vector<float, col_major, stack> v3{};
    static_cast<void>(v3);

    // my_vector v4{}; // will not compiled
    my_vector<> v4{};
    static_cast<void>(v4);
}

} // namespace example02

namespace example03 {

template <typename T, typename U = T>
class my_pair {};

void run() {
    my_pair<int, float> p1{};
    static_cast<void>(p1);

    my_pair<int> p2{};
    static_cast<void>(p2);
}
} // namespace example03

#include <iostream>
namespace example04 {

template <typename T>
T sum1(const T* array, int n) {
    T sum{0};
    for (int i = 0; i < n; ++i)
        sum += array[i];
    return sum;
}

template <typename T, unsigned N>
T sum2(const T (&array)[N]) {
    T sum{0};
    for (unsigned i = 0; i < N; ++i)
        sum += array[i];
    return sum;
}

void run() {
    int ai[] = {2, 4, 7};
    double ad[] = {2, 4.5, 7.};

    std::cout << "sum ai is " << sum1(ai, 3) << std::endl;
    std::cout << "sum ad is " << sum1(ad, 3) << std::endl;

    std::cout << "sum ai is " << sum2(ai) << std::endl;
    std::cout << "sum ad is " << sum2(ad) << std::endl;
}

} // namespace example04

#include <iostream>
namespace example05 {

template <typename T>
struct list_entry {
    list_entry(T const& value) : value_ {value}, next_{nullptr} { }

    T value_;
    list_entry<T>* next_;
};

template <typename T>
struct my_list {
    my_list() : first_{nullptr}, last_{nullptr} {}
    ~my_list() {
        while (first_) {
            list_entry<T>* tmp = first_->next_;
            delete first_;
            first_ = tmp;
        }
    }

    void append(T const& x) {
        last_ = (first_ ? last_->next_ : first_) = new list_entry<T>(x);
    }

    list_entry<T>* first_;
    list_entry<T>* last_;
};

template <typename T>
T sum(my_list<T> const& l) {
    T sum = 0;
    for (auto entry = l.first_; entry != nullptr; entry = entry->next_)
        sum += entry->value_;
    return sum;
}

void run() {
   my_list<float> l{};
   l.append(2.0f); 
   l.append(4.0f);
   l.append(7.0f);

   std::cout << "sum of the list: " << sum(l) << std::endl;
}
} // namespace example05

#include <iostream>
namespace example06 {

template <typename T>
inline T accumulate_array(T* a, T* a_end) {
    T sum{0};
    for (; a != a_end; ++a)
        sum += *a;
    return sum;
}

void run() {
    int ai[] = {2, 4, 7};
    double ad[] = {2., 4.5, 7.};
    std::cout << "sum ai is " << accumulate_array(ai, &ai[3]) << std::endl;
    std::cout << "sum ad is " << accumulate_array(ad, &ad[3]) << std::endl;
}

} // namespace example06

#include <iostream>
namespace example07 {

template <typename T>
struct list_entry {
    list_entry(T const& value) : value{value}, next{nullptr} {}

    T value;
    list_entry* next;
};

template <typename T>
struct list_iterator;

template <typename T>
struct list {
    list() : first{nullptr}, last{nullptr} {}
    ~list() {
        while (first) {
            list_entry<T>* tmp = first->next;
            delete first;
            first = tmp;
        }
    }

    void append(T const& x) {
        last = (first ? last->next : first) = new list_entry<T>(x);
    }

    list_iterator<T> begin() { return list_iterator<T>{first}; }
    list_iterator<T> end() { return list_iterator<T>{nullptr}; }

    list_entry<T>* first;
    list_entry<T>* last;
};

template <typename T>
struct list_iterator {
    using value_type = T;

    list_iterator(list_entry<T>* entry) : entry{entry} {}

    T& operator*() { return entry->value; }

    T const& operator*() const { return entry->value; }

    list_iterator<T> operator++() { entry = entry->next; return *this; }

    bool operator != (list_iterator<T> const& other) const 
    { return entry != other.entry; }

    list_entry<T>* entry;
};

template <typename Iter, typename T>
inline T accumulate(Iter it, Iter end, T init) {
    for (; it != end; ++it)
        init += *it;
    return init;
}

void run() {
    int a[] = {2, 4, 7};
    list<int> l;
    l.append(2);
    l.append(4);
    l.append(7);
    std::cout << "array sum = " << accumulate(a, a+3, 0) << std::endl;
    std::cout << "list sum = " << accumulate(l.begin(), l.end(), 0)
              << std::endl;             
}
} // namespace example07

int main() {
    example01::run();
    example02::run();
    example03::run();
    example04::run();
    example05::run();
    example06::run();
    example07::run();

    return 0;
}
