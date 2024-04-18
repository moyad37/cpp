#include "Zombie.hpp"

int main(void)
{
    Zombie* hibZombie = newZombie("HeapAbdul");
    hibZombie->announce();
    randomChump("stackHmmmmm");
    delete hibZombie;
    return 0;
}
