#ifndef CAT_HPP
# define CAT_HPP


#include "AAnimal.hpp"

class Cat : public AAnimal
{
    public:
        Cat();
        Cat(const Cat& copy);
        Cat& operator=(const Cat& copy);
        void makeSound() const;
        ~Cat();
    private:
        Brain * brain;
};



#endif
