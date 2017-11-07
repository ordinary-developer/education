#define BOOST_TEST_ALTERNATIVE_INIT_API
#include <boost/test/included/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>
#include <boost/test/parameterized_test.hpp>
#include <boost/bind.hpp>

class test_class {
    public:
        void test_method(double d) {
            BOOST_TEST(d * 100 == (double)(int)(d * 100),
                       boost::test_tools::tolerance(0.0001));
        }
} tester;

bool init_unit_test() {
    double params[] = { 1., 1.00001 };

    boost::function<void(double)> test_method = 
        boost::bind(&test_class::test_method, &tester, _1);

    boost::unit_test::framework::master_test_suite().
        add(BOOST_PARAM_TEST_CASE(test_method, params, params + 2));
                                                
    return true;
}
