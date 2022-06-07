#include <gtest/gtest.h>

#include <string>

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

std::string convertArabicNumberToRomanNumeral(unsigned int arabicNumber) {
    std::string romanNumeral{};
    while (arabicNumber >= 100) {
        romanNumeral += "C";
        arabicNumber -= 100;
    }
    while (arabicNumber >= 10) {
        romanNumeral += "X";
        arabicNumber -= 10;
    }
    while (arabicNumber >= 1) {
        romanNumeral += "I";
        arabicNumber--;
    }
    return romanNumeral;
}

class RomanNumeralAssert {
    public:
        RomanNumeralAssert() = delete;
        explicit RomanNumeralAssert(unsigned int const arabicNumber) 
            : arabicNumber_{ arabicNumber } {}

        void isConvertedToRomanNumeral(
                std::string const& expectedRomanNumeral) const 
        {
            ASSERT_EQ(expectedRomanNumeral, 
                      convertArabicNumberToRomanNumeral(arabicNumber_));
        }

    private:
        unsigned int const arabicNumber_;
};

RomanNumeralAssert assertThat(unsigned int const arabicNumber) {
    return RomanNumeralAssert{ arabicNumber };
}

TEST(ArabicToRomanNumeralConverterTestCase, 
     convertionOfArabicNumbersToRomanNumerals_Works)
{
    assertThat(1).isConvertedToRomanNumeral("I");
    assertThat(2).isConvertedToRomanNumeral("II");
    assertThat(3).isConvertedToRomanNumeral("III");

    assertThat(10).isConvertedToRomanNumeral("X");
    assertThat(20).isConvertedToRomanNumeral("XX");
    assertThat(30).isConvertedToRomanNumeral("XXX");

    assertThat(33).isConvertedToRomanNumeral("XXXIII");

    assertThat(100).isConvertedToRomanNumeral("C");
    assertThat(200).isConvertedToRomanNumeral("CC");
    assertThat(300).isConvertedToRomanNumeral("CCC");
}

