#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main(void)
{
    {
        Weapon club = Weapon("Fortnite");
        HumanA bob("Bob", club);
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }
    {
        Weapon club = Weapon("Fortnite");
        HumanB jim("Jim");
        jim.setWeapon(club);
        jim.attack();
        club.setType("FIFA");
        jim.attack();
    }

    return 0;
}
