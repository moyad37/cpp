
#include "AAnimal.hpp"

AAnimal::AAnimal() {
    this->type = "AAnimal";
	std::cout << "AAnimal Constructor called" << std::endl;
}

AAnimal::AAnimal(const AAnimal& copy)
{
	std::cout << "AAnimal (copy) constructor called." << std::endl;
	*this = copy;
}

AAnimal& AAnimal::operator=(const AAnimal& copy)
{
    std::cout << "AAnimal assignation (operator) called" << std::endl;
    if (this != &copy)
        this->type = copy.type;
    return *this;
}

std::string const& AAnimal::getType() const {
	return this->type;
}

void AAnimal::makeSound() const {
    std::cout << "Keine makeSound von calsseAAnimal" << std::endl;
}

AAnimal::~AAnimal(){
	std::cout << "AAnimal Destructor called" << std::endl;
}
