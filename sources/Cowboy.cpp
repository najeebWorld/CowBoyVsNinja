#include "Cowboy.hpp"
using namespace std;
using namespace ariel ; 

    Cowboy::Cowboy(string name, Point location) : Character(name, location,110), bullets(6) 
    {}

    void Cowboy::shoot(Character* enemy) {
        if(this->isAlive()==false || enemy->isAlive() == false)
        {
            __throw_runtime_error("the enemy is dead");
        }
        
        if(this == enemy)
        {
            __throw_runtime_error("charcter cant fight himself");
        }

        if (this->hasboolets()) {
            enemy->hit(10); // Assume each bullet deals 50 points of damage.
            bullets--;
        }
    }

    bool Cowboy::hasboolets() const {
        //__throw_runtime_error("the enemy is dead");
        return bullets > 0;
    }

    void Cowboy::reload() {
        if(this->isAlive() == false)
        {
             __throw_runtime_error("you cant reload dead chracter");
        }
        bullets = 6; // Assume a full reload gives 6 bullets.
    }

    int Cowboy::getBullets()
    {
        return bullets;
    }

    string Cowboy::print() const{
        string str = "";

        str = str + "Cowboy (" + this->getName() + ")";
        if(this->isAlive())
        {
            str = str+ "The Hit Points :" + to_string(getHitP());
            
        }
        str = str + "location : (" + to_string(this->getLocation().gitX()) + "," + to_string(this->getLocation().gitY()) ;
        return str;
    }

