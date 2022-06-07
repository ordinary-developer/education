#include <variant>
namespace workspace {

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
};
} // workspace 


int main()
{

}
    