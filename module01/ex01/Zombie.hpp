
#include <string>
# include <iostream>

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

class Zombie
{
    private:
    std::string name;
   
    public:
    Zombie();
    //Zombie(std::string name = "DefaultZombie");
    void    setZombie(std::string name);
    void    announce(void);
    ~Zombie();
};

//void randomChump(std::string name);
//Zombie*    newZombie(std::string name);
Zombie* zombieHorde( int N, std::string name );
#endif
