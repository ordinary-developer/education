#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>
#include <iostream>

BOOST_DATA_TEST_CASE(
    test1,
    boost::unit_test::data::make(2),
    singleton)
{
    std::cout << "test 1: " << singleton << std::endl;
    BOOST_TEST(2 == singleton);
}

BOOST_DATA_TEST_CASE(
    test2,
    boost::unit_test::data::xrange(3) ^ boost::unit_test::data::make(2),
    xr,
    singleton)
{
    std::cout << "test 2: " << xr << ", " << singleton << std::endl;
    BOOST_TEST(2 == singleton);
}
