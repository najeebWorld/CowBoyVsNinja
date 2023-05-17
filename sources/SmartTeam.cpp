#include "SmartTeam.hpp"

using namespace ariel;

    SmartTeam::SmartTeam(Character* leader) : leader(leader) {}

    SmartTeam::SmartTeam(const SmartTeam& other) : fighters(other.fighters), leader(other.leader) {}

    SmartTeam::SmartTeam(SmartTeam&& other) noexcept : fighters(std::move(other.fighters)), leader(std::move(other.leader)) {
        other.leader = nullptr;
    }

    SmartTeam::~SmartTeam() {
        delete leader;
        for (auto& fighter : fighters) {
            delete fighter;
        }
    }

    SmartTeam& SmartTeam::operator=(const SmartTeam& other) {
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

    SmartTeam& SmartTeam::operator=(SmartTeam&& other) noexcept {
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

    void SmartTeam::add(Character* fighter) {
        fighters.push_back(fighter);
    }

    void SmartTeam::attack(SmartTeam& enemyTeam) {
        // Here, you would need to define the logic of how a smart team attacks another team.
        // For example, you might want each fighter in this team to attack a specific fighter in the other team.
    }

    int SmartTeam::stillAlive() const {
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

    void SmartTeam::print() const {
        // Here, you would need to define the logic of how to print a smart team's details.
        // For example, you might want to print the leader's details and the details of each fighter.
    }

    const std::vector<Character *>& SmartTeam::getFighters() const {
        return fighters;
    }

    void SmartTeam::chooseNewLeader() {
        // Here, you would need to define the logic of how to choose a new leader.
        // For example, you might want to choose the fighter with the most hit points.
    }

    Character* SmartTeam::findOptimalVictim(const SmartTeam& enemyTeam) const {
        // Here, you would need to define the logic of how to find the optimal victim.
        // For example, you might want to find the enemy fighter with the least hit points.
        return nullptr;
    }

    void SmartTeam::optimizeAttackOrder() {
        // Here, you would need to define the logic of how to optimize the attack order.
        // For example, you might want to order the fighters by their speed or attack power.
    }

