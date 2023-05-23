#pragma once
#include <string>

namespace ariel{

class Point {
public:
    Point(double p_x, double p_y);
    Point();
    
    double getX ();
    double getY();
    double distance(Point other) const;
    std::string print() const;
    static Point moveTowards(Point source, Point dest, double distance) ;
    Point generateRandomPoint();
private:
    double p_x;
    double p_y;
};
}