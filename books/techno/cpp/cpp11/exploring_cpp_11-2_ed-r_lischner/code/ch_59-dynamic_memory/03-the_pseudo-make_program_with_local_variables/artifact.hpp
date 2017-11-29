#ifndef ARTIFACT_HPP_
#define ARTIFACT_HPP_

#include <chrono>
#include <string>

#include "variables.hpp"


class artifact {
    public:
        typedef std::chrono::system_clock clock;

        artifact() : name_{}, mod_time_{ clock::time_point{} } { }
        artifact(std::string const& name)
            : name_{name}, mod_time_{ get_mod_time() }, variables_{nullptr} 
        {}

        ~artifact() { delete variables_; }


        std::string const& name() const { return name_; }
        clock::time_point mod_time() const { return mod_time_; }

        std::string expand(std::string str) const 
        {
            return ::expand(str, variables_);
        }

        clock::time_point get_mod_time() { return clock::now(); }

        void store_variable(std::string const& name, 
                            std::string const& value)
        {
            if (nullptr == variables_)
                variables_ = new variable_map;
            (*variables_)[name] = value;
        }

    private: 
        std::string name_;
        clock::time_point mod_time_; 
        variable_map* variables_;
};

#endif // ARTIFACT_HPP_
