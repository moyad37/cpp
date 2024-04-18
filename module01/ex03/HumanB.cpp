#include <iostream>
#include "HumanB.hpp"


HumanB::HumanB(std::string name) : name(name){
    this->haveWeapon = false;
}

void HumanB::attack() {
    if(this->haveWeapon == false)
        std::cout << this->name << " hat keine Weapon " << std::endl;
    else
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;

}
void HumanB::setWeapon(Weapon &weapon)
{
    this->weapon = &weapon;
    this->haveWeapon = true;
}
HumanB::~HumanB() {
    std::cout << "HumanB destructor killed" << std::endl;
}
