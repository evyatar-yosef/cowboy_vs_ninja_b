#pragma once

#include "Team.hpp"

 namespace ariel{ 

class SmartTeam : public Team {
public:
     SmartTeam(Character* leader);
     SmartTeam();

     ~SmartTeam();
       SmartTeam(const SmartTeam&) = default;                    // Copy constructor
    SmartTeam& operator=(const SmartTeam&) = default;         // Copy assignment operator
    SmartTeam(SmartTeam&&) = default;                         // Move constructor
    SmartTeam& operator=(SmartTeam&&) = default;              // Move assignment operator


   void attack(Team* enemy_team) ;


};
}