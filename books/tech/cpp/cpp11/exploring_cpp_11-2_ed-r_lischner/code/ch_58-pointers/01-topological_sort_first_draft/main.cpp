#include "topological_sort.hpp"

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

typedef std::string artifact;

class dependency_graph {
    public:
        typedef std::unordered_map<artifact, 
                                   std::unordered_set<artifact>> graph_type;

        void store_dependency(artifact const& target, 
                              artifact const& dependency)
        {
            graph_[dependency].insert(target);
            graph_[target];
        }

        graph_type const& graph() const { return graph_; }

        template <class OutIter>
        void sort(OutIter sorted) const {
            topological_sort(graph_, sorted);
        }

    private:
        graph_type graph_;
};


int main() {
    dependency_graph graph{};

    std::string line{};
    while (std::getline(std::cin, line)) {
        std::string target{}, dependency{};
        std::istringstream stream{line};
        if (stream >> target >> dependency)
            graph.store_dependency(target, dependency);
        else if (not target.empty())
            std::cerr << "malformed input: target, " << target
                      << ", must be followed by a dependency name\n";
    }

    try {
        std::vector<artifact> sorted{};
        graph.sort(std::back_inserter(sorted));
        std::copy(sorted.rbegin(), 
                  sorted.rend(),
                  std::ostream_iterator<artifact>(std::cout, "\n"));
    }
    catch (std::runtime_error const& ex) {
        std::cerr << ex.what() << '\n';
        return EXIT_FAILURE;
    }

    return 0;
}
