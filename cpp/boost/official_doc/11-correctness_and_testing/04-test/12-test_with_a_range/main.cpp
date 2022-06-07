#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>
#include <iostream>

BOOST_DATA_TEST_CASE(test1, boost::unit_test::data::xrange(5)) {
    std::cout << "test 1: " << sample << std::endl;
    BOOST_TEST((sample <= 4 && sample >= 0));
}

BOOST_DATA_TEST_CASE(
    test2,
    boost::unit_test::data::xrange<int>((boost::unit_test::data::begin = 1,
                                         boost::unit_test::data::end = 10,
                                         boost::unit_test::data::step = 3)))
{
    std::cout << "test 2: " << sample << std::endl;
    BOOST_TEST((sample <= 10 && sample >= 0));
}

