#include "Team.hpp"
#include <vector>

namespace ariel {
    class Team2 : public Team {
    
    public:
        
        Team2(Character *leader);
        ~Team2() = default;

        void attack(Team* enemyTeam) override;
        int stillAlive() override;
        void print() override;
    };
}