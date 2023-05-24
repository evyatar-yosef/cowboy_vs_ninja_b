#include "SmartTeam.hpp"

namespace ariel {

    // Constructor
    SmartTeam::SmartTeam(Character* leader) : Team(leader) {}

    SmartTeam::SmartTeam() : Team() {}

    SmartTeam::~SmartTeam() {}

    void SmartTeam::add(Character* character) {}

    void SmartTeam::attack(Team* enemy_team) {}

    int SmartTeam::stillAlive() {
        return 0;
    }

    void SmartTeam::print() {}

} // namespace ariel
