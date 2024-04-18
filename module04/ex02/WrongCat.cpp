
#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	std::cout << "WrongCat default constructor called." << std::endl;
	this->type = "WrongCat";
}

WrongCat::WrongCat(WrongCat const & copy) : WrongAnimal()  {
	std::cout << "WrongCat copy constructor called." << std::endl;
	*this = copy;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor called." << std::endl;
}

WrongCat &	WrongCat::operator=(WrongCat const & copy)
{
	std::cout << "WrongCat assignment overload operator called." << std::endl;
	if (this != &copy)
		this->type = copy.type;
	return *this;
}

void	WrongCat::makeSound() const {
	std::cout << "Wrong Cat Sound : MiauMiau " << std::endl;
}
