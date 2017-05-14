#ifndef VARIABLES_HPP_
#define VARIABLES_HPP_

#include <map>
#include <string>


typedef std::map<std::string, std::string> variable_map;
extern variable_map global_variables;

std::string expand(std::string str, variable_map const* local_variables);

#endif
