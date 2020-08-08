#include <iostream>
#include <numeric>
#include <vector>
#include <execution>

double average_score_imperative(std::vector<int> const& scores) {
    int sum = 0;

    for (int score : scores)
        sum += score;

    return sum / (double)scores.size();
}

double average_score(std::vector<int> const& scores) {
    return
        std::accumulate(std::cbegin(scores), std::cend(scores), 0)
        /
        (double)scores.size();
}

double average_score_par(std::vector<int> const& scores) {
    return 
        std::reduce(std::execution::par, std::cbegin(scores), std::cend(scores), 0)
        /
        (double)scores.size();
}

double scores_product(std::vector<int> const& scores) {
    return std::accumulate(
        std::cbegin(scores), std::cend(scores), 1, std::multiplies<int>{});
}


int main(int, char**) {
    std::cout << average_score_imperative({1, 2, 3, 4}) << std::endl;
    std::cout << average_score({1, 2, 3, 4}) << std::endl;
    std::cout << average_score_par({1, 2, 3, 4}) << std::endl;
    std::cout << scores_product({1, 2, 3, 4}) << std::endl;
    
    return 0;
}
