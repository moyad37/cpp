#include "ScavTrap.hpp"


ScavTrap::ScavTrap() : ClapTrap()
{
    std::cout << "Default ScavTrap Constractor called" << std::endl;
    this->name = "Default";
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttakDamage = 20;
}

ScavTrap::ScavTrap(std::string name) 
{
    std::cout << "ScavTrap constructor(Name) called" << std::endl;
    this->name = name;
    this->HitPoints = 100;
    this->EnergyPoints = 50;
    this->AttakDamage = 20;
}

ScavTrap::ScavTrap(ScavTrap &copy)
{
    *this = copy;
    std::cout << " ScavTrap constructor(Copy) called" << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap &copy)
{
     if (this != &copy)
    {
        ClapTrap::operator=(copy);
        std::cout << "ScavTrap constructor(operator) called" << std::endl;
    }
    return (*this);
    // this->name = copy.name;
    // this->HitPoints = copy.HitPoints;
    // this->EnergyPoints = copy.EnergyPoints;
    // this->AttakDamage = copy.AttakDamage;
    std::cout << " ScavTrap constructor(operator) called" << std::endl;
    return (*this);
}

void ScavTrap::attack(const std::string& target)
{
    if(this->EnergyPoints <= 0 || this->HitPoints <= 0)
    {
        std::cout << "ScavTrap " << this->name << " has no EnergyPoints or HitPoints" << std::endl;
        return ;
    }
    else
    {
        this->EnergyPoints--;
        std::cout << "ScavTrap " << this->name << " attacks very strong" << target << ", causing " << this->AttakDamage << " points of damage!" << std::endl;
    }
    
}

// void ScavTrap::takeDamage(unsigned int amount)
// {
//     if (amount < 0)
// 		return ;
//     if(this->HitPoints - amount < 0)
//         this->HitPoints = 0;
//     else
//     {
//         this->HitPoints -= amount;
//     }
//         std::cout << "ScavTrap " << this->name << " damaged " << amount << " points from damage" << std::endl;
// }

// void ScavTrap::beRepaired(unsigned int amount)
// {
//     if (amount < 0)
// 		return ;
//     if(this->EnergyPoints <= 0 )
//     {
//         std::cout << "ScavTrap " << this->name << " has no EnergyPoints" << std::endl;
//         return ;
//     }
//     else
//     {
//         this->EnergyPoints--;
//         if ((this->HitPoints + amount) > 1000)
// 		    this->HitPoints = 1000;
//         else
//         {
//             this->HitPoints += amount;
//         }
//         std::cout << "ClapTrap " << this->name << " repaired his self  " << amount << " points from Hit Points " << std::endl;

//     }
// }

void	ScavTrap::guardGate()
{
	std::cout << "ScavTrap " << name << " is now in Gatekeeper mode." << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap Destractor called" << std::endl;
}
