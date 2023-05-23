#pragma once

#include "Team.hpp"

 namespace ariel{ 

class SmartTeam : public Team {
public:
    // SmartTeam(Character* leader);
    // SmartTeam();

    // ~SmartTeam();

    void add(Character* character) ;
   void attack(Team* enemy_team) ;
   int stillAlive() ;
    void print() ;
};
}