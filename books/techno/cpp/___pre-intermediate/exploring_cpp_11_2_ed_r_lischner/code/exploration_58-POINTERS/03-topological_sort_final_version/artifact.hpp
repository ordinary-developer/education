#ifndef ARTIFACT_HPP_
#define ARTIFACT_HPP_

#include <chrono>
#include <string>


class artifact {
    public:
        typedef std::chrono::system_clock clock;

        artifact() : name_{}, mod_time_{ clock::time_point{} } { }
        artifact(std::string const& name)
            : name_{name}, mod_time_{ get_mod_time() } { }

        std::string const& name() const { return name_; }
        clock::time_point mod_time() const { return mod_time_; }

        clock::time_point get_mod_time() { return clock::now(); }

    private: 
        std::string name_;
        clock::time_point mod_time_; 
};

#endif // ARTIFACT_HPP_
