
#pragma once
#include "Character.hpp"

namespace ariel {
class Ninja : public Character {
private:

    int speed;

public:
    Ninja(string name,Point location,int hitPoints,int speed);

    void move(Character *enemy);

    void slash(Character *enemy);

    string print() const override;
};
}
