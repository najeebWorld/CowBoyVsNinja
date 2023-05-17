
#pragma once
#include "Point.hpp"
#include <string>
using namespace std;

namespace ariel {

class Character {
private:
    Point location;
    int hitPoints;
    string name;
    char type;
    bool InTeam = false;

public:
    Character(string Name, Point location);
    Character( Character& other); // Copy constructor should take const reference
    Character(Character&& other) noexcept; // Move constructor
    //constructor with the hitPoints also. 
    Character(string name, Point location, int hitPoints);

    virtual ~Character();
    
    Character& operator=(const Character& other); // Copy assignment operator
    Character& operator=(Character&& other) noexcept; // Move assignment operator

    bool isAlive() const;
    double distance(Character* other);
    void hit(int hitting_points);
    std::string getName() const;
    Point getLocation() const;
    virtual std::string print() const = 0;
    void setLocatin(Point loc) ;

    int getHitP() const;
    bool inTeam();
    void setinTeam(bool flag);



};

}

