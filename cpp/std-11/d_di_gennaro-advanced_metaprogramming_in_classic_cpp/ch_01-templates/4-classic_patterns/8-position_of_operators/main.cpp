#include <string>
#include <iostream>
namespace example1 {
    template <typename T1, typename T2>
    struct my_pair {
        T1 first;
        T2 second;

        my_pair(const T1& aFirst, const T2& aSecond)
            : first(aFirst), second(aSecond) 
        { 
            std::cout << "Base ctor" << std::endl;
        }

        template <typename S1, typename S2>
        my_pair(const my_pair<S1, S2>& that) 
            : first(that.first), second(that.second) 
        {
            std::cout << "Convertion from S to T" << std::endl;    
        }

        inline bool operator==(const my_pair<T1,T2>& that) const {
            return (first == that.first) && (second == that.second);
        }
    };

    void run() {
        my_pair<int, std::string> P(1, "abcdef");
        my_pair<const int, std::string> Q(1, "abcdef");
        if (P == Q)
            std::cout << "P and Q are equal" << std::endl;
    }
}


#include <string>
#include <iostream>
namespace example2 {
    template <typename T1, typename T2>
    struct my_pair {
        T1 first;
        T2 second;

        my_pair(T1 const& aFirst, T2 const& aSecond) 
            : first{ aFirst }, second { aSecond } { }

        template <typename S1, typename S2>
        inline bool operator== (my_pair<S1, S2>& that) const {
            return (first == that.first) && (second == that.second);
        }
    };

    void run() {
        my_pair<int, std::string> P(1, "abcdef");
        my_pair<const int, std::string> Q(1, "abcdef");
        if (P == Q)
            std::cout << "P and Q are equal" << std::endl;

    }
}


#include <string>
#include <iostream>
namespace example3 {
    template <typename T1, typename T2>
    struct my_pair {
        T1 first;
        T2 second;

        my_pair(T1 const& aFirst, T2 const& aSecond) 
            : first{ aFirst }, second { aSecond } { }
    };

    template <typename T1, typename T2, typename S1, typename S2>
    bool operator==(my_pair<T1,T2> const& x, my_pair<S1, S2> const& y)
    {
        return (x.first == y.first) and (x.second == y.second);
    }

    void run() {
        my_pair<int, std::string> P(1, "abcdef");
        my_pair<const int, std::string> Q(1, "abcdef");
        if (P == Q)
            std::cout << "P and Q are equal" << std::endl;

    }
}

#include <string>
#include <iostream>
int main() {
    std::string lineDelimiter{ "------------------------------\r\n" };

    example1::run();
    std::cout << lineDelimiter;

    example2::run();
    std::cout << lineDelimiter;

    example3::run();
    std::cout << lineDelimiter;

    return 0;
}
