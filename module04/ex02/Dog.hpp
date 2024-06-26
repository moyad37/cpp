#ifndef DOG_HPP
# define DOG_HPP


#include "AAnimal.hpp"

class Dog : public AAnimal
{
    public:
        Dog();
        Dog(const Dog& copy);
        Dog& operator=(const Dog& copy);
        void makeSound() const;
        ~Dog();
    private:
        Brain * brain;
};



#endif
