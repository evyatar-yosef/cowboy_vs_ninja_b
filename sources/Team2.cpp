
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
    // void Team2:: attack(Team* enemy_team) {}

int Team2::stillAlive() 
{
    int charactersAlive = 0;
    if (!characters.empty())
    { 
        for(std::size_t i = 0; i < characters.size();i++)
     {

        if(characters[i]->isAlive() ) charactersAlive ++;
     }
    }
    
    
     return charactersAlive;
}

        
  //  void Team2:: print() {}

