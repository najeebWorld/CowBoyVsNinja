#ifndef TEAM_HPP
#define TEAM_HPP

#include <vector>
#include "Point.hpp"
#include "Ninja.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"

namespace ariel {
    class Team {

    private:
        Character* leader;
        vector<Character*> war ;
    
    public:
        // Regular constructor
        Team(Character* character);

        // Copy constructor
        Team(const Team& other);

        // Copy assignment operator
        Team& operator=(const Team& other);

        // Move constructor
        Team(Team&& other) noexcept;

        // Move assignment operator
        Team& operator=(Team&& other) noexcept;

        // Destructor
        virtual ~Team();

        void add(Character* warrior);
        virtual void attack(Team* enemies);
        virtual int stillAlive();
        virtual void print();
        void printCowboys();
        void printNinjas();
        

        void setLeader(Character *lead);
        Character *closestLead(Character *leader,Team *team);
        Character *getLeader();

        vector <Character*> &getwars() ;

        void attackWithNinjas(Team *opponents, Character *target);
        void attackWithCowboys(Team *opponents, Character *target);
        void updateLeaderIfNotAlive(Team *team, Character *leader);
        void validateArguments(Team *opponents);
    };

}
#endif