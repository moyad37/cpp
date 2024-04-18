
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
    this->type = ("Wrong Animal");
	std::cout << "WrongAnimal default constructor called." << std::endl;
}

WrongAnimal::WrongAnimal(WrongAnimal const & copy)
{
	std::cout << "WrongAnimal copy constructor called." << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal() {
	std::cout << "WrongAnimal destructor called." << std::endl;
}

WrongAnimal& WrongAnimal::operator=(WrongAnimal const & copy)
{
	std::cout << "WrongAnimal assignment overload operator called." << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return (*this);
}

std::string const& WrongAnimal::getType() const {
	return this->type;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal Sound : ###" << std::endl;
}
