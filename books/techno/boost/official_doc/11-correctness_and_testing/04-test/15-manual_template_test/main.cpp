#include <boost/test/included/unit_test.hpp>
#include <boost/mpl/list.hpp>

BOOST_TEST_CASE_TEMPLATE_FUNCTION(my_test, T) {
    BOOST_TEST(sizeof(T) == 4U);
}

boost::unit_test::test_suite* init_unit_test_suite(int /*argc*/, char* /*argv*/[])
{
    typedef boost::mpl::list<int, long, float> test_types;
    boost::unit_test::framework::master_test_suite().
        add(BOOST_TEST_CASE_TEMPLATE(my_test, test_types));

    return 0;
}
