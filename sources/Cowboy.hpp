#pragma once
#include "point.hpp"
#include <string>
#include "Character.hpp"
 namespace ariel{


class Cowboy : public Character
{
private:
    

public:

int numOfBullets;

Cowboy(std:: string name,Point location);
Cowboy() ;
Cowboy(Point location) ;

Cowboy(const Cowboy&) = default;
Cowboy& operator=(const Cowboy&) = default;
Cowboy(Cowboy&&) = default;
Cowboy& operator=(Cowboy&&) = default;
~Cowboy() override = default;

void shoot(Character * enemy);
bool hasboolets();
void reload();
Point getLocation();

std::string print() override;
};
}



