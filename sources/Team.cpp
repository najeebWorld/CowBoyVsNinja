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

    }


    Team::Team(const Team& other) : leader(other.leader), war(other.war) {}

    Team::Team(Team&& other) noexcept : leader(std::move(other.leader)), war(std::move(other.war)) {
        other.leader = nullptr;
    }

    Team::~Team() {
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
        if(this->war.size() >= 10)
        {
            __throw_runtime_error("the team is full");
        }
        warrior->setinTeam(true);
        this->war.push_back(warrior);
    }


void Team::attack(Team *opponents)
{
    validateArguments(opponents);
    this->leader = closestLead(this->leader,this);
    
    Character *target = closestLead(this->getLeader(),opponents );
    if (!target)
    {
        return;
    }
    attackWithCowboys(opponents, target);    
    attackWithNinjas(opponents, target);
}



void Team::validateArguments(Team *opponents)
{
    if (opponents == nullptr)
    {
        throw invalid_argument("Opponents must consist of at least one member");
    }
    if (!opponents->stillAlive())
    {
        throw runtime_error("Can't attack team without warriors");
    }
}

void Team::updateLeaderIfNotAlive(Team *team, Character *leader)
{
    if (!leader->isAlive())
    {
        leader->setinTeam(false);
        team->setLeader(closestLead(leader,team));
    }
}

void Team::attackWithCowboys(Team *opponents, Character *target)
{
    for (auto warrior : this->war)
    {
        if (!warrior->isAlive())
        {
            continue;
        }
        if(target == nullptr){return;}
        if (!target->isAlive())
        {
            target = closestLead(this->leader,opponents);
            if(target == nullptr){return;}
        }
        if (auto cowboy = dynamic_cast<Cowboy *>(warrior))
        {
            cowboy->hasboolets() ? cowboy->shoot(target) : cowboy->reload();
        }
    }
}

void Team::attackWithNinjas(Team *opponents, Character *target)
{
    for (auto warrior : war)
    {
        if (!warrior->isAlive())
        {
            continue;
        }
        if(target == nullptr) return;
        if (!target->isAlive())
        {
            target = closestLead(this->leader,opponents);
            if(target == nullptr) return;
        }
        if (auto ninja = dynamic_cast<Ninja *>(warrior))
        {
            warrior->distance(target) <= 1 ? ninja->slash(target) : ninja->move(target);
        }
    }
}


    Character *Team::closestLead(Character *charInQuestion, Team *givenTeam)
{
    double smallestDist = std::numeric_limits<double>::infinity();
    Character *prospectiveLeader = nullptr;

    auto teamMembers = givenTeam->getwars();
    for (auto currentMember : teamMembers) {
        if(currentMember->isAlive())
        {
            double currentDistance = this->leader->distance(currentMember);
            if(currentDistance < smallestDist)
            {
                prospectiveLeader = currentMember;
                smallestDist = currentDistance;
            }
        }
    }
    return prospectiveLeader;
}

        

    
    vector<Character *> &Team::getwars()
    {
        return this->war;
    }

    int Team::stillAlive() {
    int liveWarriors = 0;

    for (const auto& warrior : war) {
        if (warrior && warrior->getHitP() > 0) {
            bool isCowboy = dynamic_cast<Cowboy *>(warrior) != nullptr;
            bool isNinja = dynamic_cast<Ninja *>(warrior) != nullptr;
            
            if (isCowboy || isNinja) {
                liveWarriors++;
            }
        }
    }

    return liveWarriors;
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

