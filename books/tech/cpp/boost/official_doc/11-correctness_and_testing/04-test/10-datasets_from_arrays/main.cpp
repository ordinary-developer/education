#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>

const char* arr[] = { "cat", "dog" };

BOOST_DATA_TEST_CASE(
    test1,
    boost::unit_test::data::xrange(2) ^ boost::unit_test::data::make(arr),
    xr,
    array_element)
{
    std::cout << "test 1: " << xr << ", " << array_element << std::endl;
    BOOST_TEST(array_element != "mammoth");
}
