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

    bool Character::isAlive() const{
        if (this->hitPoints > 0)
        {
            return true;
        }
        return false;
    }

    double Character::distance(Character* other) {
        return location.distance(other->location);
    }

    void Character::hit(int hitting_points) {
    if(hitting_points < 0){
        throw std::invalid_argument ("Negative hitting point is not allowed.");
    }
    cout << "dedede" << this->getName() << endl;
    this->hitPoints -= hitting_points;
        
    // if(this->hitPoints < 0){
    //     throw std::invalid_argument ("You have negative hit point , error ");
    // }
}

    std::string Character::getName() const {
        return this->name;
    }

    Point Character::getLocation() const{
        return this->location;
    }

    

    int Character::getHitP() const
    {return this->hitPoints;}
    bool Character::inTeam(){return InTeam;}
    void Character::setinTeam(bool flag){InTeam = flag;}
    void Character::setLocatin(Point loc)
    {
        location = loc;
    }