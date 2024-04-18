#ifndef __HUMAN_A_H__
#define __HUMAN_A_H__

#include "Weapon.hpp"

class HumanA {
public:

    HumanA(std::string const &name, Weapon &weapon);
    ~HumanA();

    void attack();

private:

    std::string name;
    Weapon *weapon;
};


#endif
