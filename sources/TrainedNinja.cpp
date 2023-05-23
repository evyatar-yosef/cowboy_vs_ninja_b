#include "TrainedNinja.hpp"
using namespace ariel;


TrainedNinja::TrainedNinja (std::string name, Point location):Ninja(name,location)

{
    this -> speed = 12;
    this -> hit_points = 120;
}

TrainedNinja::TrainedNinja ():Ninja()
{
    this -> speed = 12;
    this -> hit_points = 120;
}
   
std::string TrainedNinja::print()
{
    std::string result = "Old Ninja - Name: " + name + " - HP: " + std::to_string(hit_points) + " - Location: (" + std::to_string(location.getX()) + ", " + std::to_string(location.getY()) + ")";
    return result;
}