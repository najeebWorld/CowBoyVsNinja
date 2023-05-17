#pragma once
#include <string>
using namespace std;

namespace ariel {

class Point {
public:
    Point();
    Point(double xar, double yar);
    double distance(Point poi);
    void print();
    static Point moveTowards(Point source, Point destination, double distance);
    double gitX();
    double gitY();
    
private:
    double x_;
    double y_;
};
}