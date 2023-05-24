
#include "Team2.hpp"

using namespace ariel;



    // Constructor
    Team2::Team2(Character* leader):Team(leader){}
    Team2::Team2():Team(){}
    // Destructor
    Team2::~Team2(){}
    

  //  Overridden methods from Team
    void Team2:: add(Character* character) 
    {

    if (character->inPlay == true)
    {
        throw std::runtime_error("character is already in play!");
        }
     else if( characters.size()>9){
                throw std::runtime_error("team is full!");
    } 

    
    else{ 
       characters.push_back(character);
       character->inPlay = true;
}
    }