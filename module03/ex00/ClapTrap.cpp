#include "ClapTrap.hpp"


ClapTrap::ClapTrap()
{
    std::cout << "ClapTrap Default Constractor called" << std::endl;
    this->name = "Default";
    this->HitPoints = 10;
    this->EnergyPoints = 10;
    this->AttakDamage = 0;

}

ClapTrap::ClapTrap(std::string name) : HitPoints(10), EnergyPoints(10), AttakDamage(0)
{
    this->name = name;
    std::cout << "ClapTrap constructor(Name) called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &copy)
{
    *this = copy;
    std::cout << "ClapTrap constructor(Copy) called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &copy)
{
    this->name = copy.name;
    this->HitPoints = copy.HitPoints;
    this->EnergyPoints = copy.EnergyPoints;
    this->AttakDamage = copy.AttakDamage;
    std::cout << "ClapTrap constructor(operator) called" << std::endl;
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if(this->EnergyPoints <= 0 || this->HitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << "has no EnergyPoints or HitPoints" << std::endl;
        return ;
    }
    else
    {
        this->EnergyPoints--;
        std::cout << "ClapTrap " << this->name << "  attacks " << target << ", causing " << this->AttakDamage << " points of damage!" << std::endl;
    }
    
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount < 0)
		return ;
    if(amount > 4294967295)
    {
        std::cout << "amount is not unsigned int " << std::endl;
        return ;
    }
    if(this->HitPoints - amount < 0)
        this->HitPoints = 0;
    else
    {
        this->HitPoints -= amount;
    }
        std::cout << "ClapTrap " << this->name << " damaged " << amount << " points from damage" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (amount < 0)
		return ;
    if(amount > 4294967295)
    {
        std::cout << "amount is not unsigned int " << std::endl;
        return ;
    }
    if(this->EnergyPoints <= 0 )
    {
        std::cout << "ClapTrap " << this->name << " has no EnergyPoints" << std::endl;
        return ;
    }
    else
    {
        this->EnergyPoints--;
        if ((this->HitPoints + amount) > 1000)
		    this->HitPoints = 1000;
        else
        {
            this->HitPoints += amount;
        }
        std::cout << "ClapTrap " << this->name << " repaired his self  " << amount << " points from Hit Points " << std::endl;

    }
}


ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap Destractor called" << std::endl;
}

