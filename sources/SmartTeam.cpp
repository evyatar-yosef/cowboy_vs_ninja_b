
#include "Team.hpp"
using namespace ariel;

class SmartTeam : public Team {
public:
    // Constructor
    SmartTeam(Character* leader){}
    SmartTeam(){}
    // Destructor
    ~SmartTeam(){}

    // Overridden methods from Team
    void add(Character* character) {}
    void attack(Team* enemy_team) {}
    int stillAlive() 
    {
        return 0;
    }
    void print() {}
};
