#include "Character.hpp"
#include <iostream>

using namespace ariel; 

    Character::Character(string Name, Point loc) : name(Name), location(loc) {}
    Character::Character(string name, Point location, int hitPoints) : name(name),location(location), hitPoints(hitPoints){}
    Character::Character(Character& other):name(other.name), location(other.location){}
    Character::Character(Character&& other) : name(move(other.name)), location(other.location)
    {
        other.location = Point(0,0);
    }
    

    Character::~Character() {}

    //copy opertaor 
    Character& Character::operator=(const Character& other) {
        if (this == &other) {
            return *this;
        }
        name = other.name;
        location = other.location;
        hitPoints = other.hitPoints;
        type = other.type;
        return *this;
    }

    Character& Character::operator=(Character&& other) noexcept {
        if (this == &other) {
            return *this;
        }
        name = std::move(other.name);
        location = other.location;
        hitPoints = other.hitPoints;
        return *this;
    }

    bool Character::isAlive() {
        return hitPoints > 0;
    }

    double Character::distance(Character* other) {
        return location.distance(other->location);
    }

    void Character::hit(int hitting_points) {
       if(hitPoints < 0){
        throw invalid_argument ("You have negative hit point , error ");
       }
       
        hitPoints -= hitting_points;
        
    }

    std::string Character::getName() {
        return name;
    }

    Point Character::getLocation() {
        return location;
    }

    std::string Character::print() {
        std::string info = "Name: " + name + ", Location: (" + std::to_string(location.gitX()) + ", " + std::to_string(location.gitY()) + "), Hit points: " + std::to_string(hitPoints);
        return info;
    }

    int Character::getHitP(){return hitPoints;}
    bool Character::inTeam(){return InTeam;}
    void Character::setinTeam(bool flag){InTeam = flag;}
    void Character::setLocatin(Point loc)
    {
        location = loc;
    }