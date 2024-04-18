#include "Harl.hpp"

int main(int ac, char **av)
{
    Harl harl;
    if(ac != 2)
        return (std::cout << "Nur 2 Argument bitte" << std::endl, 0);
    std::cout << GREEN << "0: DEBUG, 1:INFO, 2:WARNING, 3:ERROR" << RESET << std::endl;
    harl.complain(av[1]);
}
