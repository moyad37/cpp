#ifndef __HUMAN_B_H__
#define __HUMAN_B_H__

#include <iostream>
#include "Weapon.hpp"

class HumanB {
    public:
        HumanB(std::string name);
        ~HumanB();
        void attack();
        void setWeapon(Weapon &Weapon);
    private:
        Weapon *weapon;
        std::string name;
        bool haveWeapon;
};


#endif
