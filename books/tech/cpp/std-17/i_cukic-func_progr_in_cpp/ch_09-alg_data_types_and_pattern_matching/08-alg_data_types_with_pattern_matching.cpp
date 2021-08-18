#include <algorithm>
#include <iostream>
#include <variant>
namespace workspace {
    
template <typename... Ts>
struct overloaded : Ts... { using Ts::operator()...; };
    
template <typename... Ts> overloaded(Ts...) -> overloaded<Ts...>;

class tennis_t {
    enum class points {
        love,
        fifteen,
        thirty
    };
    
    enum class player {
        player_1,
        player_2
    };
    
    struct normal_scoring { 
        points player_1_points;
        points player_2_points;
    };
    
    struct forty_scoring {
        player leading_player;
        points other_player_scores;
    };
    
    struct deuce {};
    
    struct advantage {
        player player_with_advantage;
    };
    
    std::variant<
        normal_scoring,
        forty_scoring,
        deuce,
        advantage>
    m_state;
    
    void point_for(player which_player) {
        std::visit(
            overloaded {
                [&] (const normal_scoring& state) { std::cout << "normal scoring" << std::endl; },
                [&] (const forty_scoring& state) { std::cout << "forty scoring" << std::endl; },
                [&] (const deuce& state) { std::cout << "deuce" << std::endl; },
                [&] (const advantage& state) { std::cout << "advantage" << std::endl; }
            },
            m_state);                   
    }
};    
} // workspace 


int main() {}
