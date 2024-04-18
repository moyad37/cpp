#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#pragma once
#include <iostream>
#include "ClapTrap.hpp"
class ScavTrap : public ClapTrap
{
    public:
        // void takeDamage(unsigned int amount);
        // void beRepaired(unsigned int amount);
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(ScavTrap &copy);
        ~ScavTrap();
        ScavTrap& operator=(ScavTrap &copy);
        void attack(const std::string& target);
        void guardGate();
};



#endif
