#include "Team.hpp"
#include <cmath> // for INFINITY
#include <iostream>

using namespace std;
using namespace ariel;

    Team::Team(Character* character) : leader(character) 
    {
        this->war.clear();
        this->war.push_back(leader);
        if (this->leader->inTeam())
        {
            __throw_runtime_error("the leader in other Team");

        }

        this->leader->setinTeam(true);        
    }


    Team::Team(const Team& other) : leader(other.leader), war(other.war) {}

    Team::Team(Team&& other) noexcept : leader(std::move(other.leader)), war(std::move(other.war)) {
        other.leader = nullptr;
    }

    Team::~Team() {
        delete leader;
        for (auto& warrior : war) {
            delete warrior;
        }
    }

    Team& Team::operator=(const Team& other) {
        if (this == &other) {
            return *this;
        }
        delete leader;
        for (auto& warrior : war) {
            delete warrior;
        }
        leader = other.leader;
        war = other.war;
        return *this;
    }

    Team& Team::operator=(Team&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        delete leader;
        for (auto& warrior : war) {
            delete warrior;
        }
        leader = other.leader;
        war = other.war;
        other.leader = nullptr;
        return *this;
    }

    void Team::add(Character* warrior) {
        if(warrior->inTeam())
        {
            __throw_runtime_error("warrior in other team");
        }
        if(this->war.size() == 10)
        {
            __throw_runtime_error("the team is full");
        }
        warrior->setinTeam(true);
        this->war.push_back(warrior);
    }

    void Team::attack(Team* enemies) {

        if(!enemies->getLeader()->isAlive()) {
            throw std::runtime_error("the enemy is dead");

        }
        //first check if the leader is live
        if(enemies->getLeader()->isAlive()==false)
        {
            enemies->getLeader()->setinTeam(false);
            //define new leader to fight him
            enemies->setLeader(closestLead(leader,this));
            // enemies->setLeader(closestLead(enemies->getLeader(),enemies));
        }
        //find the close enemy to the fighter leader,if its not alive the closest one is default
        if(enemies->getLeader()->isAlive()==false)
        {
            enemies->getLeader()->setinTeam(false);
            //set the closest one to be the leader
            enemies->setLeader(closestLead(enemies->getLeader(),enemies));
        }
        //choose the close enemy to the team
        Character *selected = closestLead(this->leader,enemies);
        //war on the selected enemy with all live charecter in team

        for(auto fighter :war)
        {
            if ((enemies->stillAlive() == false) || (this->stillAlive() == false))
            {
                return;
            }
            
            //if the selected is dead , find the closest one to him
            if(selected->isAlive()==false)
            {
                selected = closestLead(selected,enemies);
            }

            Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter);

            if (cowboy != nullptr) {
                if (cowboy->hasboolets()) {
                    // Cowboy with bullets shoots victim
                    cowboy->shoot(selected);
                    } 
                    else 
                    {
                    // Cowboy without bullets loads gun
                    cowboy->reload();
                    }
            }
            // Attempt to cast warrior to Ninja
            Ninja* ninja = dynamic_cast<Ninja*>(fighter);

            if (ninja != nullptr) {
                if (fighter->distance(selected) <= 1) {
                    // Ninja within 1m of victim kills victim
                    ninja->slash(selected);
                }
            else
            {
                // Ninja further than 1m from victim moves closer
                ninja->move(selected);                }
            }

        }
    }

    
    
    Character *Team::closestLead(Character *character,Team *team)
    {
        double minDist = INFINITY;
        Character *newLeader = nullptr;

        std::vector<Character*> warriors = team->getwars();
        for (std::vector<Character*>::iterator it = warriors.begin(); it != warriors.end(); ++it) {
            Character* warrior = *it;
            if(warrior->isAlive() != false)
            {
                if(warrior!=this->leader)
                {
                    double dis = this->leader->distance(warrior);
                    if(dis<minDist)
                    {
                        newLeader =warrior;
                        minDist = dis;
                    }
                }
            }
        }


        return newLeader;
    }


    
    vector<Character *> &Team::getwars()
    {
        return this->war;
    }

    int Team::stillAlive() {
    int all_alive = 0;

    // Traverse the vector
    for (auto &warrior : war)
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


    void Team::printCowboys() {
        for (const auto &warrior : war) {
            if (dynamic_cast<Cowboy *>(warrior)) {
            cout << warrior->print() << endl;
        }
    }
    }

    void Team::printNinjas() {
        for (const auto &warrior : war) {
            if (dynamic_cast<Ninja *>(warrior)) {
            cout << warrior->print() << endl;
        }
    }
    }

    void Team::print() {
        // Note that this will print the Cowboys and Ninjas in the order they are in 'war', not in reverse
        printCowboys();
        printNinjas();
}

    void Team::setLeader(Character *lead)
    {
        this->leader=lead;
    }
    Character *Team::getLeader()
    {
        return this->leader;
    }

