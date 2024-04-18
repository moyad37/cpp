#include "ClapTrap.hpp"

#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

class FragTrap : public ClapTrap
{

public:
    FragTrap();
    FragTrap(std::string name);
    FragTrap(FragTrap &copy);
    FragTrap& operator=(FragTrap &copy);
    void highFivesGuys(void);
    ~FragTrap();
    void attack(const std::string& target);
private:
    int highFive;
};



#endif
