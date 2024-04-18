#include "FragTrap.hpp"


FragTrap::FragTrap()
{
    std::cout << "Default FragTrap Constractor called" << std::endl;
    this->name = "Default";
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttakDamage = 30;
    this->highFive = 0;
}

FragTrap::FragTrap(std::string name) 
{
    std::cout << "FragTrap constructor(Name) called" << std::endl;
    this->name = name;
    this->HitPoints = 100;
    this->EnergyPoints = 100;
    this->AttakDamage = 30;
    this->highFive = 0;
}

FragTrap::FragTrap(FragTrap &copy)
{
    *this = copy;
    std::cout << " FragTrap constructor(Copy) called" << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap &copy)
{
     if (this != &copy)
    {
        ClapTrap::operator=(copy);
        std::cout << "FragTrap constructor(operator) called" << std::endl;
    }
    return (*this);
}

// void FragTrap::attack(const std::string& target)
// {
//     if(this->EnergyPoints <= 0 || this->HitPoints <= 0)
//     {
//         std::cout << "FragTrap " << this->name << " has no EnergyPoints or HitPoints" << std::endl;
//         return ;
//     }
//     else
//     {
//         this->EnergyPoints--;
//         std::cout << "FragTrap " << this->name << " attacks " << target << ", causing " << this->AttakDamage << " points of damage!" << std::endl;
//     }
    
// }
void FragTrap::attack(const std::string& target)
{
    if(this->EnergyPoints <= 0 || this->HitPoints <= 0)
    {
        std::cout << "FragTrap " << this->name << " has no EnergyPoints or HitPoints" << std::endl;
        return ;
    }
    else
    {
        this->EnergyPoints--;
        std::cout << "FragTrap " << this->name << " attackssss" << target << this->AttakDamage << " points of damage!" << std::endl;
    }
    
}


void FragTrap::highFivesGuys( void )
{
    this->highFive++;
	std::cout << "HighFive has been called " << this->highFive << std::endl;
}

FragTrap::~FragTrap()
{
    std::cout << "FragTrap Destractor called" << std::endl;
}

