#include "Team2.hpp"

using namespace ariel;

    Team2::Team2(Character* leader) : leader(leader) {}

    Team2::Team2(const Team2& other) : fighters(other.fighters), leader(other.leader) {}

    Team2::Team2(Team2&& other) noexcept : fighters(std::move(other.fighters)), leader(std::move(other.leader)) {
        other.leader = nullptr;
    }

    Team2::~Team2() {
        delete leader;
        for (auto& fighter : fighters) {
            delete fighter;
        }
    }

    Team2& Team2::operator=(const Team2& other) {
        if (this == &other) {
            return *this;
        }
        delete leader;
        for (auto& fighter : fighters) {
            delete fighter;
        }
        leader = other.leader;
        fighters = other.fighters;
        return *this;
    }

    Team2& Team2::operator=(Team2&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        delete leader;
        for (auto& fighter : fighters) {
            delete fighter;
        }
        leader = other.leader;
        fighters = other.fighters;
        other.leader = nullptr;
        return *this;
    }

    void Team2::add(Character* fighter) {
        fighters.push_back(fighter);
    }

    void Team2::attack(Team2& enemyTeam) {
        // Here, you would need to define the logic of how a team attacks another team.
        // For example, you might want each fighter in this team to attack a specific fighter in the other team.
    }

    int Team2::stillAlive() const {
        int count = 0;
        if (leader->isAlive()) {
            count++;
        }
        for (auto& fighter : fighters) {
            if (fighter->isAlive()) {
                count++;
            }
        }
        return count;
    }

    void Team2::print() const {
        // Here, you would need to define the logic of how to print a team's details.
        // For example, you might want to print the leader's details and the details of each fighter.
    }

    void Team2::chooseNewLeader() {
        // Here, you would need to define the logic of how to choose a new leader.
        // For example, you might want to choose the fighter with the most hit points.
    }

    Character* Team2::findClosestLivingCharacter(Character* reference) const {
        // Here, you would need to define the logic of how to find the closest living character.
        // For example, you might want to find the character whose location is closest to the reference character's location.
        return nullptr;
    }

