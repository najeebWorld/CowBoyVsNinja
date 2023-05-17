#include "Ninja.hpp"

using namespace ariel;

    Ninja::Ninja(string name, Point location,int hitPoints,int speed) : Character(name,location,hitPoints), speed(speed) {}

    
    void Ninja::slash(Character* enemy){
        if(this->isAlive()==false)
        {
            __throw_runtime_error("Ninja is dead");
        }
        if(enemy->isAlive() == false)
        {
            __throw_runtime_error("The enemy is dead");
        }
        if(this == enemy)
        {
            __throw_runtime_error("Ninja cant slash himself");
        }
         if (this->distance(enemy) <= 1){
            enemy->hit(40);
        }
        }

    void Ninja::move(Character* enemy)
    {
        Point loc = Point::moveTowards(this->getLocation(),enemy->getLocation(),this->speed);
        setLocatin(loc);
    }


    
    

