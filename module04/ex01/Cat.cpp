#include "Cat.hpp"

Cat::Cat() : Animal()
{
    std::cout << "Cat constructor called " << std::endl;
    this->type = "Cat";
    try{
        this->brain = new Brain();
    }
    catch (const std::bad_alloc& leak)
    {
        std::cout << "Memory Leaks" << leak.what() << std::endl;
    }
}


Cat::Cat(const Cat& copy) : Animal(copy){
	std::cout << "Cat (Copy) Constructor called" << std::endl;
    this->type = copy.type;
	*this = copy;
}

Cat& Cat::operator=(const Cat& copy)
{
    std::cout << "Cat assignation (operator) called" << std::endl;
    if (this != &copy)
    {
        type = copy.type;
        this->brain = new Brain(*copy.brain);
    }
    return *this;
}

void Cat::makeSound() const
{
	std::cout << "Cat Sound : Miau" << std::endl;
}

Cat::~Cat()
{
     std::cout << "Cat Destructor called " << std::endl;
     delete this->brain;
}
