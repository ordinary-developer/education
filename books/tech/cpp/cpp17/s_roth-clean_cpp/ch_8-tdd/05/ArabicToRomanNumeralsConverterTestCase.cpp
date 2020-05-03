#include <gtest/gtest.h>

#include <string>
#include <cstddef>
#include <array>

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

struct ArabicToRomanMapping {
    unsigned int arabicNumber;
    std::string romanNumeral;
};

std::size_t const numberOfMappings{5};
using ArabicToRomanMappings = std::array<ArabicToRomanMapping, 
                                         numberOfMappings>;

ArabicToRomanMappings const arabicToRomanMappings = { {
    { 1000, "M" },
    {  100, "C" }, 
    {   10, "X" },
    {    5, "V" },
    {    1, "I" }
} };

std::string convertArabicNumberToRomanNumeral(unsigned int arabicNumber) {
    std::string romanNumeral{};
    for (auto const& mapping : arabicToRomanMappings) {
        while (arabicNumber >= mapping.arabicNumber) {
            romanNumeral += mapping.romanNumeral;
            arabicNumber -= mapping.arabicNumber;    
        }
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

    assertThat(5).isConvertedToRomanNumeral("V");
    assertThat(6).isConvertedToRomanNumeral("VI");

    assertThat(10).isConvertedToRomanNumeral("X");
    assertThat(20).isConvertedToRomanNumeral("XX");
    assertThat(30).isConvertedToRomanNumeral("XXX");
    assertThat(33).isConvertedToRomanNumeral("XXXIII");

    assertThat(37).isConvertedToRomanNumeral("XXXVII");

    assertThat(100).isConvertedToRomanNumeral("C");
    assertThat(200).isConvertedToRomanNumeral("CC");
    assertThat(300).isConvertedToRomanNumeral("CCC");
    assertThat(333).isConvertedToRomanNumeral("CCCXXXIII");
    
    assertThat(1000).isConvertedToRomanNumeral("M");
    assertThat(2000).isConvertedToRomanNumeral("MM");
    assertThat(3000).isConvertedToRomanNumeral("MMM");
    assertThat(3333).isConvertedToRomanNumeral("MMMCCCXXXIII");
}

