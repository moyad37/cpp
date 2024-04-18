#include "ClapTrap.hpp"

int	main()
{
	ClapTrap	a("Mensch");
	ClapTrap	b(a);
	ClapTrap	c("Luca");

	c = b;
	a.attack("Mo");
	b.takeDamage(9);
	b.takeDamage(83);
	b.beRepaired(106);
    c.attack("MMM");
    c.attack("CCCCC");
	c.attack("a");
	a.takeDamage(10);
	c.takeDamage(3);
	a.beRepaired(5);
	c.beRepaired(23);
	return (0);
}
