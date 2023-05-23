#pragma once
#include "point.hpp"
#include <iostream>
#include <string>
 namespace ariel{

class Character{

  public:
    Character(std:: string name,Point location);
     Character() ;
    // copy constructor
    Character(const Character&) = default;
    // copy assignment operator
    Character& operator=(const Character&) = default;
    // move constructor
    Character(Character&&) = default;
    // move assignment operator
    Character& operator=(Character&&) = default;
    // destructor
    virtual ~Character() = default;

    
    Point location;
    int hit_points;
    std:: string name;
    bool inPlay;


    bool isAlive();
    double distance(Character * other);
    void hit(int demage);
    std:: string getName();
    Point getLocation();
    virtual std::string print() = 0;
};
   

}