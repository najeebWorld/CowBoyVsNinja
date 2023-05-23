#include "Team.hpp"

namespace ariel {
    class SmartTeam : public Team {
    
    public:
        
        SmartTeam(Character *leader);
        
        // Copy constructor
        SmartTeam(const SmartTeam& other);

        // Move constructor
        SmartTeam(SmartTeam&& other) noexcept;
        
        // Copy assignment operator
        SmartTeam& operator=(const SmartTeam& other);
        
        // Move assignment operator
        SmartTeam& operator=(SmartTeam&& other) noexcept;
        
        // Destructor
        ~SmartTeam() override = default;

        void attack(Team* enemyTeam) override;
        
    };
}
