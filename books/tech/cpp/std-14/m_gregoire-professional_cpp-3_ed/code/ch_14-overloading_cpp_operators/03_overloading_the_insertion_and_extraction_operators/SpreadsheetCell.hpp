#ifndef SPREADSHEET_CELL
#define SPREADSHEET_CELL


#include <string>
#include <iostream>


class SpreadsheetCell {
    public:
        SpreadsheetCell();

        void set(double inValue);
        void set(const std::string& inString);

        static std::string doubleToString(double inValue);
        static double stringToDouble(const std::string& inString);

        SpreadsheetCell(double initialValue);
        explicit SpreadsheetCell(const std::string& initialValue);
        SpreadsheetCell(const SpreadsheetCell& src);

        SpreadsheetCell& operator=(const SpreadsheetCell& rhs);

        double getValue() const { mNumAccess++; return mValue; }
        const std::string& getString() const { mNumAccess++; return mString; }

        // overloading insertion and extraction operators
        friend std::ostream& operator << (std::ostream& ostr, const SpreadsheetCell& cell);
        friend std::istream& operator >> (std::istream& istr, SpreadsheetCell& cell);
    private:
        double mValue;
        std::string mString;

        mutable int mNumAccess = 0;
};
#endif 
