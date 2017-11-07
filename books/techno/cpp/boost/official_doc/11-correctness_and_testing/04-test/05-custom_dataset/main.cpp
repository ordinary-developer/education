#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>
#include <sstream>

class fibonacci_dataset {
    public:
        using sample = int;
        enum { arity = 1 };

        struct iterator {
            public:
                iterator() : a{1}, b{1} { }

                int operator*() const { return b; }
                void operator++() {
                    a = a + b;
                    std::swap(a, b);
                }

            private:
                int a;
                int b;
        };

        fibonacci_dataset() { }

        boost::unit_test::data::size_t size() const {
            return boost::unit_test::data::BOOST_TEST_DS_INFINITE_SIZE; 
        }

        iterator begin() const { return iterator(); }
};

namespace boost { 
    namespace unit_test {
        namespace data {
            namespace monomorphic {
                template <>
                struct is_dataset<fibonacci_dataset> : boost::mpl::true_ { };
            }
        }
    }
}

BOOST_DATA_TEST_CASE(
    test1,
    fibonacci_dataset() ^ boost::unit_test::data::make( 
                            { 1, 2, 3, 5, 8, 13, 21, 34, 55 }),
    fib_actual,
    expected)
{
    BOOST_TEST(fib_actual == expected);
}
