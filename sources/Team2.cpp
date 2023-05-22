#include "Team2.hpp"
#include <iostream>
using namespace ariel;

    Team2::Team2(Character* leader) : Team(leader){}

     void Team2::attack(Team *opposingTeam)
{
    if (opposingTeam == nullptr)
    {
        throw std::invalid_argument("Opposing team must contain at least one member");
    }
    
    

    // Verify if leader is alive
    if (!(opposingTeam->getLeader()->isAlive()))
    {
        opposingTeam->getLeader()->setinTeam(false);
        this->setLeader(closestLead(opposingTeam->getLeader(),this ));
    }
    // Find closest living enemy to leader
    if (!(opposingTeam->getLeader()->isAlive()))
    {
        opposingTeam->getLeader()->setinTeam(false);
        opposingTeam->setLeader(closestLead(opposingTeam->getLeader(),opposingTeam));
    }
    
    Character *target = closestLead(opposingTeam->getLeader(),opposingTeam);
    if (!target)
    {
        return;
    }
    // Execute attack with all surviving team members
    for (auto teamMember : getwars())
    {
        if ( this->getLeader()->isAlive() == 0)
        {
            return;
        }
        if (!(target->isAlive()))
        {
            target = closestLead(target,opposingTeam);
        }
        if ((dynamic_cast<Cowboy *>(teamMember) != nullptr) && (dynamic_cast<Cowboy *>(teamMember)->hasboolets()))
        {
            // Cowboy with bullets fires at target
            dynamic_cast<Cowboy *>(teamMember)->shoot(target);
        }
        else if (dynamic_cast<Cowboy *>(teamMember) != nullptr)
        {
            // Cowboy without bullets reloads gun
            dynamic_cast<Cowboy *>(teamMember)->reload();
        }
    }
    for (auto teamMember : getwars())
    {
        if ( (this->getLeader()->isAlive() == 0))
        {
            return;
        }
        
        if (!(target->isAlive()))
        {
            target = closestLead(target,opposingTeam);
        }
        if (dynamic_cast<Ninja *>(teamMember) != nullptr && teamMember->distance(target) <= 1)
        {
            // Ninja within 1m of target eliminates target
            dynamic_cast<Ninja *>(teamMember)->slash(target);
        }
        else if (dynamic_cast<Ninja *>(teamMember) != nullptr)
        {
            // Ninja further than 1m from target moves closer
            dynamic_cast<Ninja *>(teamMember)->move(target);
        }
    }
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

