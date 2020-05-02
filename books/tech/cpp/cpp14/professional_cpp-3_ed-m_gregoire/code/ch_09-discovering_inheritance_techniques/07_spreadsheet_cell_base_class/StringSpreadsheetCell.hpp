#ifndef STRING_SPREAD_SHEET_CELL_HPP
#define STRING_SPREAD_SHEET_CELL_HPP

#include "SpreadsheetCell.hpp"

#include <string>


class StringSpreadsheetCell : public SpreadsheetCell {
    public:
        StringSpreadsheetCell();
        virtual void set(const std::string& inString) override;
        virtual std::string getString() const override;
    private:
        std::string mValue;
};

#endif
