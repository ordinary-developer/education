#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>
#include <iostream>

BOOST_DATA_TEST_CASE(
    test1,
    boost::unit_test::data::random(1, 17) ^ boost::unit_test::data::xrange(7),
    random_sample,
    index)
{
    std::cout << "test 1: " << random_sample << ", " << index << std::endl;
    BOOST_TEST((random_sample <= 17 && random_sample >= 1));
}

BOOST_DATA_TEST_CASE(
    test,
    boost::unit_test::data::random(
        (boost::unit_test::data::distribution = 
            std::uniform_real_distribution<float>{ 1, 2 }))
    ^  
    boost::unit_test::data::xrange(7),
    random_sample,
    index)
{
    std::cout << "test 2: " << random_sample << ", " << index << std::endl;
    BOOST_TEST(random_sample < 2.0);
}
        
