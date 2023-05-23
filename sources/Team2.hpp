#include "Team.hpp"
#include <vector>

namespace ariel {
    class Team2 : public Team {
    public:
        
        Team2(Character *leader);
        
        // Copy constructor
        Team2(const Team2& other) = default;

        // Move constructor
        Team2(Team2&& other) noexcept = default;
        
        // Copy assignment operator
        Team2& operator=(const Team2& other) = default;
        
        // Move assignment operator
        Team2& operator=(Team2&& other) noexcept = default;

        // Destructor
        ~Team2() override = default;

        void attack(Team* enemyTeam) override;
        int stillAlive() override;
        void print() override;
    };
}
