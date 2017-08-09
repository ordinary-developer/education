#include <boost/test/included/unit_test.hpp>
#include <boost/bind.hpp>

class test_class {
    public:
        void test_method1() {
            BOOST_TEST(true);
        }

        void test_method2() {
            BOOST_TEST(true);
        }
};

boost::unit_test::test_suite* init_unit_test_suite(int /*argc*/, char* /*argv*/[])
{
    boost::shared_ptr<test_class> tester{ new test_class{} };

    boost::unit_test::framework::master_test_suite().
        add(BOOST_TEST_CASE(boost::bind(&test_class::test_method1, tester)));
    boost::unit_test::framework::master_test_suite().
        add(BOOST_TEST_CASE(boost::bind(&test_class::test_method2, tester)));

    return 0;
}
