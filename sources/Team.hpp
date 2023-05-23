#pragma once

#include <vector>
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "Character.hpp"

 namespace ariel{ 

class Team {
    public:
        Team(Character* leader);
         Team();
        // Team(const Team&) = default;
        // Team& operator=(const Team&) = default;
        // Team(Team&&) = default;
        // Team& operator=(Team&&) = default;
        ~Team();

        void add(Character* character);
        void attack(Team* enemy_team);
        int stillAlive();
        void print();
        std::vector<Character*> characters;


        int numCowboys;
        int numNinjas;
    private:
       // std::vector<Character*> characters;
        Character* leader;



};
 }