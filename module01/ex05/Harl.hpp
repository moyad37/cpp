#ifndef HARL_H
# define HARL_H

#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>

#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define BLUE "\033[1;34m"
#define BRAUN "\033[1;33m"
#define RESET "\033[0m"

class Harl
{
    private:
        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
        struct lev
        {
            std::string level;
            void (Harl::*f)(void);
        };
        
    public:
        void complain( std::string level );
        Harl();
        ~Harl();
};






#endif
