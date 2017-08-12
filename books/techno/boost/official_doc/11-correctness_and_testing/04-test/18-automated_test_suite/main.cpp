#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_SUITE(test_suite_example)

BOOST_AUTO_TEST_CASE(test_case1) 
{
    BOOST_TEST_WARN(sizeof(int) < 4U);
}

BOOST_AUTO_TEST_CASE(test_case2) {
    BOOST_TEST_REQUIRE(1 == 2);
    BOOST_FAIL("Should never reach this line");
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE(test_suite2)

BOOST_AUTO_TEST_CASE(test_case3)
{
    BOOST_TEST(true);
}

BOOST_AUTO_TEST_CASE(test_case4)
{
    BOOST_TEST(false);
}

BOOST_AUTO_TEST_SUITE_END()
