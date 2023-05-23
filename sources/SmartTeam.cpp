#include "SmartTeam.hpp"

namespace ariel {

    // Constructor
    SmartTeam::SmartTeam(Character *leader) : Team(leader) {
        // Constructor implementation
    }

    
    // Overridden attack function
    void SmartTeam::attack(Team* enemyTeam) {
        this->validateArguments(enemyTeam);
        this->setLeader(closestLead(this->getLeader(),this));

        Character *target = closestLead(this->getLeader(),enemyTeam );
        if (!target)
        {
            return;
        }
        for (auto warrior : this->getwars())
        {
            if (!warrior->isAlive())
            {
                continue;
            }
            if (!target->isAlive())
            {
                target = closestLead(this->getLeader(),enemyTeam);
                if(target == nullptr){return;}
            }
            if (auto cowboy = dynamic_cast<Cowboy *>(warrior))
            {
                cowboy->hasboolets() ? cowboy->shoot(target) : cowboy->reload();
            }
            if (auto ninja = dynamic_cast<Ninja *>(warrior))
            {
                warrior->distance(target) <= 1 ? ninja->slash(target) : ninja->move(target);
            }
        }
    }

    
}
