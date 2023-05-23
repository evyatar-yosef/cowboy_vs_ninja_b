#pragma once
#include "Character.hpp"
#include <string>
#include <mutex>
#include "point.hpp" 
 namespace ariel{ 

class Ninja : public Character
{
private:    

public:
Ninja (std :: string name, Point location);
Ninja();
std::mutex mutex;
int speed;
std::string getName();
void move(Character * enemy);
void slash(Character * enemy);
std::string print() override;
Point getLocation();


};
 }