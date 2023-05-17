#include "Point.hpp"
#include <iostream>
#include <cmath>

using namespace ariel;

    //default constructor 
    Point::Point() : x_(0), y_(0) {}

    Point::Point(double xar, double yar) : x_(xar), y_(yar) {}

    double Point::distance(Point poi) {
        double dx = x_ - poi.x_;
        double dy = y_ - poi.y_;
        return sqrt(dx*dx + dy*dy);
    }

    void Point::print() {
        std::cout << "(" << x_ << ", " << y_ << ")" << std::endl;
    }

    Point Point::moveTowards(Point source, Point destination, double distance) {
        if(distance < 0 ){
            throw std::invalid_argument("distance cant be < 0");
        }

        //calc the dist between source and destination
        double totalDistance = source.distance(destination);

        if (totalDistance < distance) {
            return destination;
        } 
        
        else {
            double ratio = distance / totalDistance;
            double newX = source.gitX() + (ratio * (destination.gitX() - source.gitX()));
            double newY = source.gitY() + (ratio * (destination.gitY() - source.gitY()));
            return Point(newX, newY);
        }
    }

    double Point::gitX() {
        return x_;
    }

    double Point::gitY() {
        return y_;
    }

