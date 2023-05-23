#include "Ninja.hpp"
#include <random>
#include <thread>
#include <chrono>
#include <stdexcept>

using namespace ariel;


Ninja::Ninja(std::string name, Point location) : Character(name, location) 
{
    this->name = name;
    this->location = location;
}

Ninja::Ninja():Character()
{
    this->name = "BOT_NINJA";
    this->location = Point().generateRandomPoint();
}


Point Ninja:: getLocation()
{
    return this-> location;
}

std::string Ninja:: getName()
{
    return this-> name; 
}

 void Ninja::move(Character *enemy) {
        if(!this->isAlive()){
        throw std::runtime_error(" dead ninja");
        }
        this->location=Point::moveTowards(location,enemy->location,speed);
    }

void Ninja::slash(Character* enemy)
{
    if (enemy == this) {
        throw std::runtime_error("Cannot attack oneself");
    }
    
    if (!enemy->isAlive()) {
        throw std::runtime_error("Cannot attack a dead enemy.");
    }

    if (!isAlive()) {
        throw std::runtime_error("Dead characters cannot attack.");
    }

    if (distance(enemy) < 1) {
        enemy->hit(40);
    }
    else {
        // Attack has no effect
        return;
    }
}



std::string Ninja:: print()
{
    return "";

}
