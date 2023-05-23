#include "OldNinja.hpp"
using namespace ariel;


OldNinja::OldNinja (std::string name, Point location):Ninja(name,location)

{
    this -> speed = 8;
    this -> hit_points = 150;
}
OldNinja::OldNinja ():Ninja()

{
    this -> speed = 8;
    this -> hit_points = 150;
}
   


std::string OldNinja::print()
{
    std::string result = "Old Ninja - Name: " + name + " - HP: " + std::to_string(hit_points) + " - Location: (" + std::to_string(location.getX()) + ", " + std::to_string(location.getY()) + ")";
    return result;
}