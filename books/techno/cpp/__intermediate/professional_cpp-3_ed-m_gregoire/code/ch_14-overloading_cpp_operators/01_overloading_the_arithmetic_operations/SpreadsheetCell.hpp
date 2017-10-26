#ifndef SPREADSHEET_CELL
#define SPREADSHEET_CELL


#include <string>

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

        // [OPERATORS OVERLOADING] 
        // unary operators
        SpreadsheetCell operator-() const;
        // prefix and postfix operators
        SpreadsheetCell& operator++(); //prefix
        SpreadsheetCell operator++(int); //postfix
        SpreadsheetCell& operator--(); //prefix
        SpreadsheetCell operator--(int); // postfix

        SpreadsheetCell& operator += (const SpreadsheetCell& rhs);
        SpreadsheetCell& operator -= (const SpreadsheetCell& rhs);
        SpreadsheetCell& operator *= (const SpreadsheetCell& rhs);
        SpreadsheetCell& operator /= (const SpreadsheetCell& rhs);

        friend SpreadsheetCell operator + (const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
        friend SpreadsheetCell operator - (const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
        friend SpreadsheetCell operator * (const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
        friend SpreadsheetCell operator / (const SpreadsheetCell& lhs, const SpreadsheetCell& rhs);
    private:
        double mValue;
        std::string mString;

        mutable int mNumAccess = 0;
};
#endif 
