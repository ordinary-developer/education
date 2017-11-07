#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>
#include <boost/mpl/list.hpp>

typedef boost::mpl::list<int, long, float> test_types;

BOOST_AUTO_TEST_CASE_TEMPLATE(my_test, T, test_types) {
    BOOST_TEST(sizeof(T) == (unsigned)4);
}
