#pragma once

#include "Team.hpp"

namespace ariel {

    class Team2 : public Team {
    public:
        Team2(Character* leader);
        Team2();

        ~Team2();

         // Define the special member functions as default
    Team2(const Team2&) = default;                    // Copy constructor
    Team2& operator=(const Team2&) = default;         // Copy assignment operator
    Team2(Team2&&) = default;                         // Move constructor
    Team2& operator=(Team2&&) = default;              // Move assignment operator


        void add(Character* character);
       
    };

} // namespace ariel
