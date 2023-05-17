#include "Team.hpp"

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
        
    }

    int Team::stillAlive() {
        int count = 0;
        if (leader->isAlive()) {
            count++;
        }
        for (auto& warrior : war) {
            if (warrior->isAlive()) {
                count++;
            }
        }
        return count;
    }

    void Team::print() {
        // Here, you would need to define the logic of how to print a team's details.
        // For example, you might want to print the leader's details and the details of each warrior.
    }

