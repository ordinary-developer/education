#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>
#include <iostream>
#include <random>

BOOST_DATA_TEST_CASE(
    test1,
    boost::unit_test::data::xrange(2) * boost::unit_test::data::xrange(3),
    xr1, xr2)
{
    std::cout << "test 1: " << xr1 << ", " << xr2 << std::endl;
    BOOST_TEST((xr1 <= 2 && xr2 <= 3));
}

BOOST_DATA_TEST_CASE(
    test2,
    boost::unit_test::data::xrange(3) * (boost::unit_test::data::random(
                                            boost::unit_test::data::distribution =
                                              std::uniform_real_distribution<float>
                                                ( 1, 2))
                                         ^
                                         boost::unit_test::data::xrange(2)),
    xr,
    random_sample,
    index)
{
    std::cout << "test 2: " << xr << " / " << random_sample << ", " << index
              << std::endl;
    BOOST_TEST(random_sample < 2);
}

