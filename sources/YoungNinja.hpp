#pragma once
#include "Ninja.hpp"
#include <iostream>
#include <string>

 namespace ariel{ 

class YoungNinja : public Ninja{

public:
    YoungNinja(std::string name, Point location);
    YoungNinja();
    std::string print() override;

    //int demage_point;



};
 }