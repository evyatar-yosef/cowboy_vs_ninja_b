#include "YoungNinja.hpp"
using namespace ariel;

YoungNinja::YoungNinja (std::string name, Point location):Ninja(name,location)

{
    this -> speed = 14;
    this -> hit_points = 100;
}

YoungNinja::YoungNinja ():Ninja()

{
    this -> speed = 14;
    this -> hit_points = 100;
}

std::string YoungNinja::print()
{
    std::string result = "Old Ninja - Name: " + name + " - HP: " + std::to_string(hit_points) + " - Location: (" + std::to_string(location.getX()) + ", " + std::to_string(location.getY()) + ")";
    return result;
}