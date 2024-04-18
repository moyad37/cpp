#include "Weapon.hpp"

Weapon::Weapon(std::string type)
{
    this->type = type;
    std::cout << "constructor Ok" << std::endl;
}


const std::string   Weapon::getType(void) {
    return ((const std::string) this->type);
}

void                Weapon::setType(std::string type) {
    this->type = type;
}

Weapon::~Weapon() {
    std::cout << "Weapon destructor killed" << std::endl;
}
