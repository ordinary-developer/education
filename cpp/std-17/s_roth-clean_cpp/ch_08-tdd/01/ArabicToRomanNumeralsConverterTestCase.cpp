#include <gtest/gtest.h>

#include <string>

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

std::string convertArabicNumberToRomanNumeral(unsigned int const arabicNumber) {
    return "I";
}

TEST(ArabicToRomanNumeralsConverterTestCase, PreparationsCompleted) {
    ASSERT_EQ("I", convertArabicNumberToRomanNumeral(1));
}
