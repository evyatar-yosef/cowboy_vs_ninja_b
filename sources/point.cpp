#include "point.hpp"
#include <cmath>
#include <iostream>
#include <random>
using namespace ariel;

Point::Point(double P_x, double P_y)    
{ 
  this->p_x = P_x;
  this->p_y = P_y;  
}

Point::Point()
{
}

double Point::distance(Point other) const {
    double xDiff = other.p_x - this->p_x;
    double yDiff = other.p_y - this->p_y;
    double distance = std::sqrt(xDiff * xDiff + yDiff * yDiff);
    return distance;
}


   std::string Point::print() const {
   
   std::string x = "(" + std::to_string(p_x) + ", " + std::to_string(p_y) + ")";
   return x;

}
Point Point::moveTowards(Point source, Point dest, double distance)
{
    if (distance <= 0)
    {
        throw std::invalid_argument("Invalid distance");
    }

    double distanceToDest = source.distance(dest);
    if (distanceToDest <= distance)
    {
        return dest;
    }
    else
    {
        double dx = dest.getX() - source.getX();
        double dy = dest.getY() - source.getY();
        double ratio = distance / distanceToDest;
        double normalizedDx = dx / distanceToDest;
        double normalizedDy = dy / distanceToDest;
        double newX = source.getX() + normalizedDx * distance;
        double newY = source.getY() + normalizedDy * distance;
        return Point(newX, newY);
    }
}



double Point:: getX()
{
    return this ->p_x;
}
double Point:: getY()
{
    return this ->p_y;
}

Point Point::generateRandomPoint()
{
    // Generate random x and y coordinates within the range of -10 to 10
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> dis(-10.0, 10.0);

    double randomX = dis(gen);
    double randomY = dis(gen);

    return Point(randomX, randomY);
}