#ifndef WEAPON_CLASS_H
# define WEAPON_CLASS_H

#include <iostream>

class Weapon {
    public:
        Weapon(std::string type);
        const std::string   getType();
        void                setType(std::string type);
        ~Weapon();

    private:
        std::string type;
};

#endif
