#include "Dog.hpp"

Dog::Dog() : Animal()
{
    std::cout << "Dog constructor called " << std::endl;
    this->type = "Dog";
}


Dog::Dog(const Dog& copy) : Animal(copy){
	std::cout << "Dog (Copy) Constructor called" << std::endl;
    this->type = copy.type;
	*this = copy;
}

Dog& Dog::operator=(const Dog& copy)
{
    std::cout << "Dog assignation (operator) called" << std::endl;
    if (this != &copy)
        type = copy.type;
    return *this;
}

void Dog::makeSound() const
{
	std::cout << "Dog Sound : Hu Hu" << std::endl;
}

Dog::~Dog()
{
     std::cout << "Dog Destructor called " << std::endl;
}
