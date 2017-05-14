#ifndef VITAL_STATS_HPP_
#define VITAL_STATS_HPP_

#include <iosfwd>
#include <string>

class vital_stats {
    public:
        vital_stats() 
        : height_{ 0 }, weight_{ 0 }, bmi_{ 0 }, sex_{ '?' }, name_{}
        { }

        bool read(std::istream& in, int num);
        void print(std::ostream& out, int threshold) const;

        int bmi() const { return bmi_; }
        int height() const { return height_; }
        int weight() const { return weight_; }
        char sex() const { return sex_; }
        std::string const& name() const { return name_; }

    private:
        int compute_bmi() const;
        
        int height_;
        int weight_;
        int bmi_;
        char sex_;
        std::string name_;
};

#endif
