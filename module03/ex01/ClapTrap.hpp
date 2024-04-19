#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


#include <iostream>

class ClapTrap
{
    protected:
        std::string name;
        int HitPoints;
        int EnergyPoints;
        int AttakDamage;
    public:
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ClapTrap();
        ClapTrap(ClapTrap &copy);
        ClapTrap(std::string name);
        ClapTrap &operator=(ClapTrap &copy);
        ~ClapTrap();
        std::string getName();
		int getHitPoint();
		int getEnergyPoints();
		int getAttackDamage();

};



#endif
