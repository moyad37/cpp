#include "Zombie.hpp"


void    Zombie::setZombie(std::string name)
{
    this->name = name;
}

Zombie* zombieHorde( int N, std::string name )
{
    if(N <= 0){
        std::cout << "keine Zombie N" << std::endl;
        return NULL;
    }
    else{
        Zombie* zombies = new Zombie[N];
        for (int i = 0; i < N; ++i){
            //zombies[i] = Zombie();
            zombies[i].setZombie(name);
            std::cout << i << " ";
            zombies[i].announce();
            // new (&zombies[i]) Zombie(name);
            // std::cout << i << " ";
            // zombies[i].announce();
        }
        return zombies;
    }
    // Allocate memory for the array of zombies
    //char* buffer = new char[N * sizeof(Zombie)];

    // Create zombies using placement new
    //Zombie* zombies = reinterpret_cast<Zombie*>(buffer);
}

