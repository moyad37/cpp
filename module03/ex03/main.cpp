#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int	main()
{
	DiamondTrap dt("Ironmann");
	DiamondTrap dt2("Spidermann");
	DiamondTrap dt3;
	dt3 = dt2;

	dt.whoAmI();
	dt.attack("42");

	dt3.whoAmI();
	dt3.attack("Auto");
	return 0;
}
