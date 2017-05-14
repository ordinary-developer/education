#pragma once

#include "Gadget.hpp"

#include <string>
#include <vector>

class Widget { 
    public:
        Widget() { }

    private:
        std::string name;
        std::vector<double> data;
        Gadget g1, g2, g3;
};
