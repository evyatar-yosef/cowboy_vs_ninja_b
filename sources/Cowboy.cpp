#include "Cowboy.hpp"
using namespace ariel;


Cowboy :: Cowboy(std:: string name,Point location):Character(name,location)
{
    this-> name = name;
     this-> location = location;
     this->numOfBullets = 6;
     this->hit_points = 110;
}
Cowboy :: Cowboy(Point location):Character()
{
     this-> name = "clint eastwood";
     this-> location = location;
     this->numOfBullets = 6;
     this->hit_points = 110;
}

Cowboy :: Cowboy()
{
     this-> name = "clint eastwood";
     this-> location = Point().generateRandomPoint();
     this->numOfBullets = 6;
     this->hit_points = 110;
}



Point Cowboy:: getLocation()
{
    return this->location;
}



void Cowboy:: shoot(Character * enemy)
{
     if (enemy == this) {
        throw std::runtime_error("Cannot shoot oneself");
    }

     if (!isAlive()) {
        throw std::runtime_error("Dead characters cannot attack.");
    }

    if (!enemy->isAlive()) {
        throw std::runtime_error("Cannot attack a dead enemy.");
    }
   if( this->hasboolets() == true){
    enemy->hit(10);
    numOfBullets--;
   }
   return;
}

bool Cowboy:: hasboolets()
{
    if(numOfBullets > 0) return true;
    return false;
}


void Cowboy::reload()
{
    if (!isAlive()) {
        throw std::runtime_error("Cannot reload: dead cowboy");
    }

    numOfBullets = 6;
}

std::string Cowboy::print()
{
    std::string result;

    if (!isAlive()) {
        result += "(";
    }

    result += "C Cowboy ";

    if (isAlive()) {
        result += name + " - HP: " + std::to_string(hit_points) + " - Location: (" + std::to_string(location.getX()) + ", " + std::to_string(location.getY()) + ")";
    } else {
        result += name + ")";
    }

    return result;
}
