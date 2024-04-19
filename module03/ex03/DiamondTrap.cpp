#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
{
    std::cout << "DiamondTrap Default Constructor" << std::endl;
}


DiamondTrap::DiamondTrap(std::string name) : FragTrap(name + "_clap_name"), ScavTrap(name + "_clap_name")
{
	std::cout << "DiamondTrap (Name) Constructor called" << std::endl;
	this->name = name;
}

DiamondTrap::DiamondTrap(DiamondTrap& copy) : FragTrap(copy), ScavTrap(copy)
{
	std::cout << "DiamondTrap (Copy) Constructor" << std::endl;
}


DiamondTrap& DiamondTrap::operator=(DiamondTrap& copy)
{
    std::cout << "DiamondTrap Copy assignment Operator" << std::endl;
    this->name = copy.name;
    FragTrap::name = name + "_clap_name";
    this->ScavTrap::EnergyPoints = copy.ScavTrap::EnergyPoints;
    this->FragTrap::AttakDamage = copy.FragTrap::AttakDamage;
    this->FragTrap::HitPoints = copy.FragTrap::HitPoints;
    return *this;
}
void DiamondTrap::whoAmI()
{
	std::cout << "I'm " << this->name << " - " << this->FragTrap::name << std::endl;
}

void DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap Destructor called" << std::endl;
}
