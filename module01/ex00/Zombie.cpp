
#include "Zombie.hpp"
#include <cstdlib>

Zombie::Zombie(std::string name)
{
    this->name = name;
}

void	Zombie::announce(void)
{
    std::cout << (this->name) << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie() {}


