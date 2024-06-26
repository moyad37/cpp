#include "ClapTrap.hpp"


ClapTrap::ClapTrap()
{
    std::cout << "Default Constractor called" << std::endl;
    this->name = "Default";
    this->HitPoints = 10;
    this->EnergyPoints = 10;
    this->AttakDamage = 0;
}

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->HitPoints = 10;
    this->EnergyPoints = 10;
    this->AttakDamage = 0;
    std::cout << "constructor(Name) called" << std::endl;
}

ClapTrap::ClapTrap(ClapTrap &copy)
{
    *this = copy;
    std::cout << "constructor(Copy) called" << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap &copy)
{
    this->name = copy.name;
    this->HitPoints = copy.HitPoints;
    this->EnergyPoints = copy.EnergyPoints;
    this->AttakDamage = copy.AttakDamage;
    std::cout << "constructor(operator) called" << std::endl;
    return (*this);
}

void ClapTrap::attack(const std::string& target)
{
    if(this->EnergyPoints <= 0 || this->HitPoints <= 0)
    {
        std::cout << "ClapTrap " << this->name << " has no EnergyPoints or HitPoints" << std::endl;
        return ;
    }
    else
    {
        this->EnergyPoints--;
        std::cout << "ClapTrap " << this->name << " attacks " << target << ", causing " << this->AttakDamage << " points of damage!" << std::endl;
    }
    
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (amount < 0)
		return ;
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


std::string ClapTrap::getName(){
	return(this->name);
}

int ClapTrap::getHitPoint(){
	return(this->HitPoints);
}

int ClapTrap::getEnergyPoints(){
	return(this->EnergyPoints);
}

int ClapTrap::getAttackDamage(){
	return(this->AttakDamage);
}

void ClapTrap::setName(std::string name){
	this->name = name;
}

void ClapTrap::setHitPoint(int hP){
	this->HitPoints = hP;
}

void ClapTrap::setEnergyPoints(int eP){
	this->EnergyPoints = eP;
}

void ClapTrap::setAttackDamage(int aD){
	this->AttakDamage = aD;
}


ClapTrap::~ClapTrap()
{
    std::cout << "Destractor called" << std::endl;
}

