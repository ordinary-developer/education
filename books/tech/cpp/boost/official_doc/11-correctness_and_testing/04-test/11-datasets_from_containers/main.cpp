#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>
#include <boost/test/data/test_case.hpp>
#include <boost/test/data/monomorphic.hpp>
#include <sstream>
#include <vector>
#include <cstddef>
#include <iostream>
#include <map>
#include <string>
#include <utility>

std::vector<float> fibonacci() {
    std::vector<float> ret(8);
    ret[0] = 0;
    ret[1] = 1;

    for (std::size_t s{2}; s < ret.size(); ++s)
        ret[s] = ret[s - 1] + ret[s - 2];

    return ret;
}

BOOST_DATA_TEST_CASE(
    test1,
    boost::unit_test::data::make(fibonacci()),
    array_element)
{
    std::cout << "test 1: " << array_element << std::endl;
    BOOST_TEST(array_element <= 13);
}

std::map<std::string, float> vect_2_str(std::vector<float> v) {
    std::map<std::string, float> out{};
    for (std::size_t s{0}; s < v.size(); ++s) {
        std::ostringstream o{};
        o << v[s];
        out[o.str()] = v[s];
    }
    return out;
}

typedef std::pair<const std::string, float> pair_map_t;
BOOST_TEST_DONT_PRINT_LOG_VALUE(pair_map_t)

BOOST_DATA_TEST_CASE(
    test2,
    boost::unit_test::data::make(vect_2_str(fibonacci())),
    array_element)
{
    std::cout << "test 2: \"" 
              << array_element.first << "\", " << array_element.second 
              << std::endl;
    BOOST_TEST(array_element.second <= 13);
}


