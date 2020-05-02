#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(free_test_function)
{
    BOOST_TEST(true);
}

boost::unit_test::test_suite* init_unit_test_suite(int /*argc*/, char* /*argv*/[])
{
    boost::unit_test::framework::master_test_suite().p_name.value = 
        "my master test suite name";
    return 0;
}
