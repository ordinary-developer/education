#include <cmath>
#include <numeric>
#include <vector>
#include <iostream>


namespace stats {
    class std {
        public:
            std(double mean) : mean_{ mean } { }

            double operator()(double acc, double x) const {
                return acc + square(x - mean_);
            }

            double square(double x) const { return x * x; }

        private:
            double mean_;
    };

    double stats(::std::vector<double> const& data) {
        double std{ 0.0 };
        if (not data.empty()) {
            double sum{ ::std::accumulate(data.begin(), data.end(), 0.0) };
            double mean{ sum / data.size() };
            double sumsq{ ::std::accumulate(data.begin(),
                                            data.end(),
                                            0.0,
                                            stats::std(mean)) };
            double variance{ sumsq / data.size() - mean * mean };
            std = ::std::sqrt(variance);
        }
        return std;
    }
}


int main() {
    std::vector<double> a{ 1, 2, 3, 4, 5, 100, 200, 300, 400, 500 };
    std::cout << stats::stats(a) << std::endl;

    return 0;
}
