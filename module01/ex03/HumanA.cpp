#include <iostream>
#include "HumanA.hpp"

// HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(&weapon) {
// }

// HumanA::~HumanA(void) {
// }

// void    HumanA::attack(void) {
//     std::cout << this->name + " attacks with their " + this->weapon->getType() << std::endl;
// }


HumanA::HumanA(std::string const & name, Weapon &weapon){
    this->name = name;
    this->weapon = &weapon;
}

void HumanA::attack() {
    std::cout << this->name << " attacks with their  " << this->weapon->getType() << std::endl;
}

HumanA::~HumanA() {
    std::cout << "HumanA destructor killed" << std::endl;
}

