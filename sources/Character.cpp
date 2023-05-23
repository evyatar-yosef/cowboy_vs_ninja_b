#include "Character.hpp"
#include <cmath>
#include <iostream>
using namespace ariel;

    
    Character::Character(std:: string name,Point location)
    {
        this-> name = name;
        this-> location = location;
        this-> inPlay = false;
         
    }
    Character::Character()
    {
        this-> inPlay = false;
    }
    
    bool Character:: isAlive()
    {
         if (this-> hit_points <= 0 ) return false;
        return true;
    }

    
 double Character::distance(Character* other)
{
   
    double distance = this->location.distance(other->location);
    return distance;
}


    void Character:: hit(int demage)
    {
        
         if (demage < 0) {
        throw std::invalid_argument("Invalid damage value: must be non-negative");
    }
        if(hit_points<=0)  throw std::runtime_error("Cannot attack a dead enemy.");
         
        this->hit_points = hit_points - demage;
        return; 
    }
    
    std:: string Character:: getName()
    {
        return name;
    }
    Point Character:: getLocation()
    {
        return location;
    }
     std::string  Character::print()
    {
        return "";
    }
