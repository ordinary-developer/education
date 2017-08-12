#include <boost/test/included/unit_test.hpp>

void free_test_function() {
    BOOST_TEST(true);
}

boost::unit_test::test_suite* init_unit_test_suite(int /*argc*/, char* /*argv*/[])
{
    if (boost::unit_test::framework::master_test_suite().argc > 1)
        return 0;

    boost::unit_test::framework::master_test_suite().
        add(BOOST_TEST_CASE(&free_test_function));

    return 0;
}
