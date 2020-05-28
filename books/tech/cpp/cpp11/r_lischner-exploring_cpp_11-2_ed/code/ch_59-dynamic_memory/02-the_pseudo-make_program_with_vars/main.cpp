#include "artifact.hpp"
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
#include <map>
#include <vector>


class dependency_graph {
    public:
        typedef 
          std::unordered_map<artifact*, 
                             std::unordered_set<artifact*>> graph_type;

        void store_dependency(artifact* target, 
                              artifact* dependency)
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

std::map<std::string, artifact> artifacts{};
artifact* lookup_artifact(std::string const& name) {
    auto iterator = artifacts.find(name);
    if (artifacts.end() == iterator)
        artifacts.emplace(name, artifact{name});
    return &artifacts[name];
}


typedef std::map<std::string, std::string> variable_map;
variable_map variables{};

std::string expand(std::string str) {
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
            str.replace(pos, end - pos + 1, variables[varname]);
            start = pos;
        }
    }
}

void parse_graph(std::istream& in, dependency_graph& graph) {
    std::string line{};
    while (std::getline(in, line)) {
        std::string target_name{}, dependency_name{};
        std::istringstream stream{line};
        if (stream >> target_name >> dependency_name)
        {
            artifact* target{lookup_artifact(expand(target_name))};
            artifact* dependency{lookup_artifact(expand(dependency_name))};
            graph.store_dependency(target, dependency);
        }
        else if (not target_name.empty()) {
            std::string::size_type equal{ target_name.find('=') };
            if (std::string::npos == equal) {
                std::cerr << "malformed input: target, " << target_name
                          << ", must be followed by a dependency name\n";
            }
            else {
                std::string variable_name{ target_name.substr(0, equal) };
                std::string variable_value{ target_name.substr(equal + 1) };
                variables[variable_name] = variable_value;
            }
        }
    }
}


int main() {
    dependency_graph graph{};

    parse_graph(std::cin, graph);

    try {
        std::vector<artifact*> sorted;
        graph.sort(std::back_inserter(sorted));

        for (auto it(sorted.rbegin()), end(sorted.rend());
             it != end;
             ++it)
        {
            std::cout << (*it)->name() << '\n';
        }
    }
    catch (std::runtime_error const& ex) {
        std::cerr << ex.what() << '\n';
        return EXIT_FAILURE;
    }
    
    return 0;
}
