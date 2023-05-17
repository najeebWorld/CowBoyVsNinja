#include "Team.hpp"

using namespace ariel;

    Team::Team(Character* character) : leader(character) {}

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
        war.push_back(warrior);
    }

    void Team::attack(Team* enemies) {
        // Here, you would need to define the logic of how a team attacks another team.
        // For example, you might want each warrior in this team to attack a random warrior in the other team.
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

