#include "Team2.hpp"
#include <iostream>
using namespace ariel;

    Team2::Team2(Character* leader) : Team(leader){}

    void Team2::attack(Team *opposingTeam)
    {
        this->validateArguments(opposingTeam);
        this->setLeader(closestLead(this->getLeader(),this));

        Character *target = closestLead(this->getLeader(),opposingTeam );
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
                target = closestLead(this->getLeader(),opposingTeam);
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
        // Find closest living enemy to leader
    }


    int Team2::stillAlive() {

    int all_alive = 0;

    // Traverse the vector
    for (auto &warrior : this->getwars())
    {
        // Check if the character is alive
        if (warrior && warrior->getHitP() > 0)
        {
            // Check if it's a cowboy or a ninja and increment all_alive
            all_alive += dynamic_cast<Cowboy *>(warrior) != nullptr || dynamic_cast<Ninja *>(warrior) != nullptr;
        }
    }

    return all_alive;
}

void Team2::print()
{
    // Obtain the vector of warriors from the getWarriors() function
    std::vector<Character*> warriors = this->getwars(); 

    // Loop over each warrior in the warriors vector
    for (auto warrior : warriors)
    {
        // Check if the warrior is not a null pointer and if it is alive
        if (warrior && warrior->isAlive())
        {
            // Print the warrior's information to the console
            std::cout << warrior->print() << std::endl;
        }
    }
}

