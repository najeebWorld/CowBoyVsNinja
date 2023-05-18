#include "Team2.hpp"
#include <iostream>
using namespace ariel;

    Team2::Team2(Character* leader) : Team(leader){}

    void Team2::attack(Team* enemies) {
        // //first check if the leader is live
        // if(enemies->getLeader()->isAlive()==false)
        // {
        //     enemies->getLeader()->setinTeam(false);
        //     //define new leader to fight him
        //     enemies->setLeader(closestLead(leader,this));
        //     // enemies->setLeader(closestLead(enemies->getLeader(),enemies));
        // }
        // //find the close enemy to the fighter leader,if its not alive the closest one is default
        // if(enemies->getLeader()->isAlive()==false)
        // {
        //     enemies->getLeader()->setinTeam(false);
        //     //set the closest one to be the leader
        //     enemies->setLeader(closestLead(enemies->getLeader(),enemies));
        // }
        // //choose the close enemy to the team
        // Character *selected = closestLead(this->leader,enemies);
        // //war on the selected enemy with all live charecter in team

        // for(auto fighter :war)
        // {
        //     if ((enemies->stillAlive() == false) || (this->stillAlive() == false))
        //     {
        //         return;
        //     }
            
        //     //if the selected is dead , find the closest one to him
        //     if(selected->isAlive()==false)
        //     {
        //         selected = closestLead(selected,enemies);
        //     }

        //     Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter);

        //     if (cowboy != nullptr) {
        //         if (cowboy->hasboolets()) {
        //             // Cowboy with bullets shoots victim
        //             cowboy->shoot(selected);
        //             } 
        //             else 
        //             {
        //             // Cowboy without bullets loads gun
        //             cowboy->reload();
        //             }
        //     }
        //     // Attempt to cast warrior to Ninja
        //     Ninja* ninja = dynamic_cast<Ninja*>(fighter);

        //     if (ninja != nullptr) {
        //         if (fighter->distance(selected) <= 1) {
        //             // Ninja within 1m of victim kills victim
        //             ninja->slash(selected);
        //         }
        //     else
        //     {
        //         // Ninja further than 1m from victim moves closer
        //         ninja->move(selected);                }
        //     }

        // }
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

