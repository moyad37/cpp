#ifndef DIAMONDTRAP_HPP
#define DIAMONDTRAP_HPP

#include "ClapTrap.hpp"
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap
{
    private:
    std::string name;
    public:
        DiamondTrap();
        DiamondTrap(std::string name);
		DiamondTrap(DiamondTrap& copy);
		DiamondTrap& operator=(DiamondTrap& copy);
		void whoAmI();
		void attack(const std::string& target);
		std::string getName();
		void setName(std::string);
        ~DiamondTrap();
};


#endif
