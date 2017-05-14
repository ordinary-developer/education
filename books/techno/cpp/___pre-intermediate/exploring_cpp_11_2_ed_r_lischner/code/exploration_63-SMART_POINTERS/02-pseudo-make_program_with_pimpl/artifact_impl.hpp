#ifndef ARTIFACT_IMPL_HPP_
#define ARTIFACT_IMPL_HPP_

#include <chrono>
#include <string>

#include "variables.hpp"


class artifact_impl {
    public:
        typedef std::chrono::system_clock clock;

        artifact_impl() : name_{}, mod_time_{ clock::time_point{} } {}

        artifact_impl(std::string const& name)
            : name_{name}, mod_time_{get_mod_time()}, variables_{nullptr} 
        {}
        
        artifact_impl(artifact_impl const&) = delete;

        artifact_impl(artifact_impl&& source) noexcept
            : name_{ std::move(source.name_) },
              mod_time_{ std::move(source.mod_time_) },
              variables_{ source.variables_ }
        {
            source.variables_ = nullptr;
        }

        ~artifact_impl() { delete variables_; }

        artifact_impl& operator=(artifact_impl&& source) noexcept {
            delete variables_;
            variables_ = source.variables_;
            source.variables_ = nullptr;
            name_ = std::move(source.name_);
            mod_time_ = std::move(source.mod_time_);
            return *this;
        }

        artifact_impl& operator=(artifact_impl&) = delete;

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

#endif // ARTIFACT_IMPL_HPP_
