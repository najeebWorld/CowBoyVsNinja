#include "Ninja.hpp"

namespace ariel
{
    class OldNinja : public Ninja
    {
        public:
        OldNinja(string Name, Point location);
        void move(Character* enemy) override;
    };
}
