#include <vector>
#include "Point.hpp"
#include "Ninja.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"

const unsigned int NUM_WAR = 10;
namespace ariel {
    class Team {

    private:
        Character* leader;
        vector<Character*> war {NUM_WAR};
    
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
        ~Team();

        void add(Character* warrior);
        virtual void attack(Team* enemies);
        virtual int stillAlive();
        virtual void print();

        void setLeader(Character *lead);
        Character *getLeader();

        vector <Character*> &getwars();
        Character *near(Team *team,Character *lead);
    };
}