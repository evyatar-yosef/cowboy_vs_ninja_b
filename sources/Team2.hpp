#pragma once

#include "Team.hpp"

namespace ariel {

    class Team2 : public Team {
    public:
        Team2(Character* leader);
        Team2();

        ~Team2();

        void add(Character* character);
        // void attack(Team* enemy_team);
        int  stillAlive();
       // void print();
    };

} // namespace ariel
