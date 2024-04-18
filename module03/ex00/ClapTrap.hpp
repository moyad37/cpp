#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP


#include <iostream>

class ClapTrap
{
    private:
        std::string name;
        int HitPoints;
        int EnergyPoints;
        int AttakDamage;
    public:
        void attack(const std::string& target);
        void takeDamage(unsigned int amount);
        void beRepaired(unsigned int amount);
        ClapTrap();
        ClapTrap(const ClapTrap &copy);
        ClapTrap(std::string name);
        ClapTrap &operator=(const ClapTrap &copy);
        ~ClapTrap();
};



#endif
