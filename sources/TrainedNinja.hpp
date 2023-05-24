#pragma once
#include "Ninja.hpp"
#include <iostream>
#include <string>
namespace ariel{

class TrainedNinja : public Ninja{

public:
    TrainedNinja(std::string name, Point location);
    TrainedNinja();
    std::string print() override;




    //int demage_point;



};
}