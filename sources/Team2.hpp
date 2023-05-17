#include "Point.hpp"
#include "Ninja.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <vector>

namespace ariel {
    class Team2 {
    private:
        std::vector<Character *> fighters;
        Character *leader;

        void chooseNewLeader();
        Character *findClosestLivingCharacter(Character *reference) const;

    public:
        // Copy constructor
        Team2(const Team2& other);

        // Copy assignment operator
        Team2& operator=(const Team2& other);

        // Move constructor
        Team2(Team2&& other) noexcept;

        // Move assignment operator
        Team2& operator=(Team2&& other) noexcept;

        Team2(Character *leader);
        ~Team2();

        void add(Character *fighter);
        void attack(Team2 &enemyTeam);
        int stillAlive() const;
        void print() const;
    };
}