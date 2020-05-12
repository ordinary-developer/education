#ifndef SPREAD_SHEET_CELL_HPP
#define SPREAD_SHEET_CELL_HPP

#include <string>


class SpreadsheetCell {
    public:
        SpreadsheetCell();
        virtual ~SpreadsheetCell();
        virtual void set(const std::string& inString) = 0;
        virtual std::string getString() const = 0;
};

#endif
