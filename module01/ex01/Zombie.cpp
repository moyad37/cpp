
#include "Zombie.hpp"
#include <cstdlib>

Zombie::Zombie()
{
    this->name = "DefaultZombie";
}

// Zombie::Zombie()
// {
//     this->name = name;
// }

void	Zombie::announce(void)
{
    std::cout << (this->name) << ": " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->name << ": Killed" << std::endl;
}
