#include <boost/test/included/unit_test.hpp>
#include <boost/test/parameterized_test.hpp>

void free_test_function(int i) {
    BOOST_TEST(i < 5);
}

boost::unit_test::test_suite* init_unit_test_suite(int /*argc*/, char* /*argv*/[]) 
{
    int params[] = { 0, 1, 2, 3, 4 };
    boost::unit_test::framework::master_test_suite().
        add(BOOST_PARAM_TEST_CASE(&free_test_function, params, params + 5));

    return 0;
}
