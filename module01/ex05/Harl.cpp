#include "Harl.hpp"
Harl::Harl() {}

void    Harl::debug(void)
{
    std::cout << BLUE << "From Debug" << RESET << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << RED << "From info" << RESET << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}


void    Harl::warning(void)
{
    std::cout << GREEN << "From warning" << RESET << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << BRAUN << "From error" << RESET << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}


void Harl::complain(std::string level)
{
    lev alles[4];

    alles[0].level = "DEBUG";
    alles[0].f = &Harl::debug;
    alles[1].level = "INFO";
    alles[1].f = &Harl::info;
    alles[2].level = "WARNING";
    alles[2].f = &Harl::warning;
    alles[3].level = "ERROR";
    alles[3].f = &Harl::error;

    for (int i = 0; i < 4; i++)
    {
        if (alles[i].level == level)
        {
             void (Harl::*fun)(void) = alles[i].f;
            (this->*fun)();
        }
    }
    
}

Harl::~Harl()
{
    //std::cout << "Destractor killed" << std::endl;
}
