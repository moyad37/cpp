#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int	main()
{
ScavTrap	scav( "Messi" );

	scav.attack( "Ronaldo" );
	scav.takeDamage(140);
	scav.beRepaired(80);
	scav.guardGate();
	return 0;
}
