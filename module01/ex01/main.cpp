#include "Zombie.hpp"

int main(void)
{
    const int numZombies = 5;
    std::string zombieName = "MO";

    Zombie* zombieArray = zombieHorde(numZombies, zombieName);

    // // Announce each zombie
    // for (int i = 0; i < numZombies; ++i) {
    //     zombieArray[i].announce();
    // }

    // for (int i = 0; i < numZombies; ++i) {
    //     zombieArray[i].~Zombie();
    // }
    // Delete the array of zombies
    //zombieArray->~Zombie();
    delete[] zombieArray;

    return 0;
}
