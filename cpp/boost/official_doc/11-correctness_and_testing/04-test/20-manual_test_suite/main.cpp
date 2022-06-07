#include <boost/test/included/unit_test.hpp>

void test_case1() { }
void test_case2() { }
void test_case3() { }
void test_case4() { }


boost::unit_test::test_suite* init_unit_test_suite(int /*argc*/, char* /*argv*/[]) {
    boost::unit_test::test_suite* ts1 = BOOST_TEST_SUITE("test_suite1");
    ts1->add(BOOST_TEST_CASE(&test_case1));
    ts1->add(BOOST_TEST_CASE(&test_case2));

    boost::unit_test::test_suite* ts2 = BOOST_TEST_SUITE("test_suite2");
    ts1->add(BOOST_TEST_CASE(&test_case3));
    ts1->add(BOOST_TEST_CASE(&test_case4));

    boost::unit_test::framework::master_test_suite().add(ts1);
    boost::unit_test::framework::master_test_suite().add(ts2);

    return 0;
}
