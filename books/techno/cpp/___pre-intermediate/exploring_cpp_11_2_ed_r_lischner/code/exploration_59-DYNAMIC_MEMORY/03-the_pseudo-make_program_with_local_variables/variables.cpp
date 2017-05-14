#include "variables.hpp"

variable_map global_variables{};

std::string get_value(std::string const& name, 
                      variable_map const* local_variables)
{
    if (nullptr != local_variables) {
        variable_map::const_iterator iter{ local_variables->find(name) };
        if (local_variables->end() != iter)
            return iter->second;
    }
    return global_variables[name];
}

std::string expand(std::string str, variable_map const* local_variables) {
    std::string::size_type start{0};
    while (true) {
        std::string::size_type pos{ str.find('$', start) };
        if (std::string::npos == pos)
            return str;
        if ((str.size() - 1) == pos or '(' != str[pos + 1]) 
            start = pos + 1;
        else {
            std::string::size_type end{ str.find(')', pos) };
            if (std::string::npos == end)
                return str;

            std::string varname{ str.substr(pos + 2, end - pos - 2) };
            std::string value{ get_value(varname, local_variables) };
            str.replace(pos, end - pos + 1, value);
            start = pos;
        }
    }
}

