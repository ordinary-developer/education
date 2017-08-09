#define BOOST_TEST_MODULE MyTest
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(first_test)
{
    int i{1};
    BOOST_TEST(i);
    BOOST_TEST(1 == i);
}
