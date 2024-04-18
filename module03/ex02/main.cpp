#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main()
{
	FragTrap	frag( "Messi" );
	ScavTrap	scav( "Halland" );

	frag.attack( "Ronaldo" );
	scav.attack("Vini");
	frag.takeDamage(140);
	scav.takeDamage(110);
	frag.beRepaired(80);
	frag.highFivesGuys();
	frag.highFivesGuys();
	frag.highFivesGuys();
	return 0;
}
