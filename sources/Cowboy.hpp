#ifndef COWBOY_HPP
#define COWBOY_HPP
#pragma once
#include "Character.hpp"

namespace ariel{
class Cowboy : public Character {
private:
    int bullets;

public: 
    Cowboy(string name,Point location);
    void shoot(Character* enemy);
    bool hasBullets() const;
    void reload();
    string print();
    int getBullets();
};
}
#endif // COWBOY_HPP