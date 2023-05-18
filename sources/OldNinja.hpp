#ifndef OLD_NINJA_HPP
#define OLD_NINJA_HPP

#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
        public:
        OldNinja(string Name, Point location);
        //void move(Character* enemy) override;
    };
}

#endif // OLD_NINJA_HPP
