
#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain Constructor called" << std::endl;
}

Brain::~Brain(){
	std::cout << "Brain Destructor called" << std::endl;
}

Brain::Brain(const Brain& copy){
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = copy;
}

Brain& Brain::operator=(const Brain& copy)
{
    std::cout << "Brain assignation operator called" << std::endl;
     if (this != &copy)
	 {
		size_t length = sizeof(ideas) / sizeof(ideas[0]);
		for (size_t i = 0; i < length; i++)
			ideas[i] = copy.ideas[i];
	 }
    return *this;
}
