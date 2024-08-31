
#include "Animal.hpp"

Animal::Animal() {
    this->type = "Animal";
	std::cout << "Animal Constructor called" << std::endl;
}

Animal::Animal(const Animal& copy)
{
	std::cout << "Animal (copy) constructor called." << std::endl;
	*this = copy;
}

Animal::~Animal(){
	std::cout << "Animal Destructor called" << std::endl;
}

Animal& Animal::operator=(const Animal& copy)
{
    std::cout << "Animal assignation (operator) called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

std::string const& Animal::getType() const {
	return this->type;
}

void Animal::makeSound() const {
    std::cout << "No makeSound from calss Animal" << std::endl;
}
